#include "mainwindowimpl.h"
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f)
    : QMainWindow(parent, f)
{
    //	ui init

    setupUi(this);
    sett = 0;
    kern = 0;
    log = 0;
    init();
}




MainWindowImpl::~MainWindowImpl()
{
    reinit_vars();
}





int MainWindowImpl::reinit_vars()
{
    hide();
    if( sett != 0 )
    {
        delete sett;
        sett = 0;
    }
    if( kern != 0 )
    {
        delete kern;
        kern = 0;
    }
    return 0;
}






int MainWindowImpl::init()
{
    //	start settings
    sett = new settings(QString("lobanovs"), QString("stokroom"), this);
    connect(sett, SIGNAL( quit() ), this, SIGNAL( quit() ) );
    if( sett->init() )
    {
        qDebug("Settings init returns non zero");
        exit(1);
    }

    //	initialization of log class
    log = new log_impl(this);
    QString log_path;
    if( sett->get_log_path( &log_path ) )
    {
        qDebug("MainWindowImpl::init can't get log path");
        exit(1);
    }
    if(log->init( log_path )) exit(1);
    connect(sett, SIGNAL( log(QString, QString) ), log, SLOT( log(QString, QString) ) );
    connect(this, SIGNAL( log_message(QString, QString) ), log, SLOT( log(QString, QString) ) );


    //	init kernel
    QDir u_path;
    if ( sett->get_upath(u_path) )
    {
        QMessageBox::critical(this, QString("Init"), QString("Can't recive user folder."));
        exit(1);
    }
    kern = new kernel(this);
    connect(kern, SIGNAL( log(QString, QString) ), log, SLOT( log(QString, QString) ) );
    connect(kern, SIGNAL(updateSummaryTable(QVector<summary_record*>*)), sum_table, SLOT(updateSummaryTable(QVector<summary_record*>*)));
    connect(kern, SIGNAL(updateActivityTable(QVector<action_record>)), activityTable, SLOT(updateActivityTable(QVector<action_record>)));
    if( kern->lock( u_path ) )
    {
        exit(1);
    }

    this->initComboBoxes();
    show();
    return 0;
}
















quint8 MainWindowImpl::initComboBoxes()
{
    QStringList varitys, selections, montYears;
    kern->getRoundsFor(QString(tr("All")), QString(tr("All")), tr("All"), &varitys, &selections, &montYears);

    this->setComboBox(aVariant, varitys, tr("All"));

    this->setComboBox(aSelection, selections, tr("All"));

    this->setComboBox(aMonthYear, montYears, QDateTime::currentDateTime().toString(CURRENT_FILE_NAME_PATTERN));

    this->currentActVarity = new QString( tr("All") );
    this->currentActSelection = new QString( tr("All") );
    this->currentActMonthYear = new QString( QDateTime::currentDateTime().toString(CURRENT_FILE_NAME_PATTERN) );

    return 0;
}













quint8 MainWindowImpl::activityCommoBoxesSignalBlock(bool block)
{
    aVariant->blockSignals(block);
    aSelection->blockSignals(block);
    aMonthYear->blockSignals(block);
    return 0;
}









quint8 MainWindowImpl::getCurrentActivityRoundSelection(QString *varity, QString *selection, QString *monthYear)
{
    *varity = aVariant->currentText();
    *selection = aSelection->currentText();
    *monthYear = aMonthYear->currentText();
    return 0;
}








//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//				slots
void MainWindowImpl::logout()
{
    //	delete vars
    reinit_vars();
    init();
}










void MainWindowImpl::addItem()
{
    add_item addIt(this);
    connect(&addIt, SIGNAL(log(QString,QString)), log, SLOT(log(QString,QString)));
    if( QDialog::Rejected == addIt.exec() ) return;
    QString varity, selection, description;
    quint64 box, item;
    bool save;
    if(addIt.getValues(&varity, &selection, &box, &item, &save, &description)) return;
    kern->addItemRecord(varity, selection, box, item, description, save);

    this->activityRoundsChanged();
}






void MainWindowImpl::loadItem()
{
    summary_record *record;
    QString rowId;
    if(sum_table->getActiveRowID(&rowId)) return;
    record = kern->getRecordByID(rowId);
    if(record == 0) return;
    load_item loadIt(this, kern, record->variant, record->selection);
    loadIt.setTitle(tr("Load ") + record->variant + QString("/") + QString::number(record->selection));
    connect(&loadIt, SIGNAL(log(QString,QString)), log, SLOT(log(QString,QString)));
    if(QDialog::Rejected == loadIt.exec()) return;

    quint64 dateTime, boxCount, itemCount;
    QString description;
    if(loadIt.getValues(&dateTime, &boxCount, &itemCount, &description)) return;

    if(kern->addActionToItem(record->id, QString("l"), dateTime, boxCount, itemCount, description)) return;

    return;
}






void MainWindowImpl::unloadItem()
{
    summary_record *record;
    QString rowId;
    if(sum_table->getActiveRowID(&rowId)) return;
    record = kern->getRecordByID(rowId);
    if(record == 0) return;
    load_item loadIt(this, kern, record->variant, record->selection);
    loadIt.setTitle(tr("Unload ") + record->variant + QString("/") + QString::number(record->selection));
    connect(&loadIt, SIGNAL(log(QString,QString)), log, SLOT(log(QString,QString)));
    if(QDialog::Rejected == loadIt.exec()) return;

    quint64 dateTime, boxCount, itemCount;
    QString description;
    if(loadIt.getValues(&dateTime, &boxCount, &itemCount, &description)) return;

    if(kern->addActionToItem(record->id, QString("u"), dateTime, boxCount, itemCount, description)) return;

    return;
}












void MainWindowImpl::activityRoundsChanged()
{

    QString var, sel, mY;
    QString nV, nS, nD;
    QStringList nVarL, nSelL, nMYL;
    this->getCurrentActivityRoundSelection(&var, &sel, &mY);


    if(var.isEmpty() || sel.isEmpty() || mY.isEmpty()) return;

    //  varity changed
    if(var != *this->currentActVarity)
    {
        //  varity modified
        if(kern->getRoundsFor(var, sel, mY, &nVarL, &nSelL, &nMYL)) return;

        //if count of items in varity combo box not equal to count of items in varity list update it
        nV = var;

        if(this->setComboBox(aVariant, nVarL, nV)) return;

        //  set selection combobox
        if(nSelL.indexOf(*this->currentActSelection) != -1) nS = *this->currentActSelection;
        else nS = tr("All");

        if(this->setComboBox(aSelection, nSelL, nS)) return;

        //  set month year combo box
        if(nMYL.indexOf(*this->currentActMonthYear) != -1) nD = *this->currentActMonthYear;
        else nD = QDateTime::currentDateTime().toString(CURRENT_FILE_NAME_PATTERN);

        if(this->setComboBox(aMonthYear, nMYL, nD)) return;

        kern->setActivitySelection(var, nS, nD);
        *this->currentActVarity = nV;
        *this->currentActSelection = nS;
        *this->currentActMonthYear = nD;
        return;
    }



    //  selection changed
    if(sel != *this->currentActSelection)
    {
        //  varity modified
        if(kern->getRoundsFor(var, sel, mY, &nVarL, &nSelL, &nMYL)) return;

        //varity
        if(this->setComboBox(aVariant, nMYL, nD)) return;

        //  set month year combo box
        if(nMYL.indexOf(*this->currentActMonthYear) != -1) nD = *this->currentActMonthYear;
        else nD = QDateTime::currentDateTime().toString(CURRENT_FILE_NAME_PATTERN);

        if(this->setComboBox(aMonthYear, nMYL, nD)) return;

        kern->setActivitySelection(*this->currentActVarity, sel, nD);
        *this->currentActSelection = sel;
        *this->currentActMonthYear = nD;
        return;
    }



    //  date changed
    if(mY != *this->currentActMonthYear)
    {
        kern->setActivitySelection(*this->currentActVarity, *this->currentActSelection, mY);
        *this->currentActMonthYear = mY;
        return;
    }

    return;
}








quint8 MainWindowImpl::setComboBox(QComboBox *comboBox, QStringList items, QString currentItem)
{
    comboBox->blockSignals(true);

    if(items.indexOf(currentItem) == -1)
    {
        emit log_message(QString(Q_FUNC_INFO), QString("Index %1 not founded in items list").arg(currentItem));
        return 1;
    }

    comboBox->clear();
    comboBox->addItems(items);

    comboBox->setCurrentIndex(comboBox->findText(currentItem));

    comboBox->blockSignals(false);

    return 0;
}









//
