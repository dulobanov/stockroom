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


    this->currentActVarity = new QString("");
    this->currentActSelection = new QString("");
    this->currentActMonthYear = new QString("");
    this->currentRepVarity = new QString("");
    this->currentRepSelection = new QString("");
    this->currentRepMonthYear = new QString("");

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
    connect(kern, SIGNAL(updateReportTable(QVector<action_record>)), reportTable, SLOT(updateReportTable(QVector<action_record>)));
    if( kern->lock( u_path ) )
    {
        exit(1);
    }

    //this->initComboBoxes();
    this->activityRoundsChanged();
    this->reportRoundsChanged();
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






quint8 MainWindowImpl::getCurrentReportRoundSelection(QString *varity, QString *selection, QString *monthYear)
{
    *varity = rVariant->currentText();
    *selection = rSelection->currentText();
    *monthYear = rMonthYear->currentText();
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
    this->reportRoundsChanged();
}






void MainWindowImpl::loadItem()
{
    summary_record *record;
    QString rowId;
    if(sum_table->getActiveRowID(&rowId)) return;
    record = kern->getRecordByID(rowId);
    if(record == 0) return;
    LoadUnloadItem loadIt(this, kern, record->variant, record->selection);
    connect(&loadIt, SIGNAL(log(QString,QString)), log, SLOT(log(QString,QString)));
    loadIt.setTitle(tr("Load ") + record->variant + QString("/") + QString::number(record->selection));
    loadIt.setMaxBoxItemCount(MAX_COUNT - record->box_count, MAX_COUNT - record->item_count);
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
    LoadUnloadItem loadIt(this, kern, record->variant, record->selection);
    connect(&loadIt, SIGNAL(log(QString,QString)), log, SLOT(log(QString,QString)));
    loadIt.setTitle(tr("Unload ") + record->variant + QString("/") + QString::number(record->selection));
    loadIt.setMaxBoxItemCount(record->box_count, record->item_count);
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
    QStringList nVarL, nSelL, nMYL;
    this->getCurrentActivityRoundSelection(&var, &sel, &mY);

    if(var.isEmpty()) var = tr("All");
    if(sel.isEmpty()) sel = tr("All");
    if(mY.isEmpty()) mY = QDateTime::currentDateTime().toString(CURRENT_FILE_NAME_PATTERN);

        //  varity modified
    if(kern->getRoundsFor(var, sel, mY, &nVarL, &nSelL, &nMYL)) return;

    if(nVarL.isEmpty() || nSelL.isEmpty() || nMYL.isEmpty()) return;

    if(this->setComboBox(aVariant, nVarL, var)) return;
    if(this->setComboBox(aSelection, nSelL, sel)) return;
    if(this->setComboBox(aMonthYear, nMYL, mY)) return;

    kern->setActivitySelection(var, sel, mY);
    *this->currentActVarity = var;
    *this->currentActSelection = sel;
    *this->currentActMonthYear = mY;
    return;
}








void MainWindowImpl::reportRoundsChanged()
{

    QString var, sel, mY;
    QStringList nVarL, nSelL, nMYL;
    this->getCurrentReportRoundSelection(&var, &sel, &mY);

    if(var.isEmpty()) var = tr("All");
    if(sel.isEmpty()) sel = tr("All");
    if(mY.isEmpty()) mY = QDateTime::currentDateTime().toString(CURRENT_FILE_NAME_PATTERN);

        //  varity modified
    if(kern->getRoundsFor(var, sel, mY, &nVarL, &nSelL, &nMYL)) return;

    if(nVarL.isEmpty() || nSelL.isEmpty() || nMYL.isEmpty()) return;

    if(this->setComboBox(rVariant, nVarL, var)) return;
    if(this->setComboBox(rSelection, nSelL, sel)) return;
    if(this->setComboBox(rMonthYear, nMYL, mY)) return;

    kern->setReportSelection(var, sel, mY);
    *this->currentRepVarity = var;
    *this->currentRepSelection = sel;
    *this->currentRepMonthYear = mY;
    return;
}








quint8 MainWindowImpl::setComboBox(QComboBox *comboBox, QStringList items, QString currentItem)
{
    QString item;
    comboBox->blockSignals(true);

    if(items.indexOf(currentItem) == -1)
    {
        emit log_message(QString(Q_FUNC_INFO), QString("Index %1 not founded in items list").arg(currentItem));
        item = items.at(0);
    }
    else
    {
        item = currentItem;
    }

    comboBox->clear();
    comboBox->addItems(items);

    comboBox->setCurrentIndex(comboBox->findText(item));

    comboBox->blockSignals(false);

    return 0;
}









//
