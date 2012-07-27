#ifndef MA_LOG_H
#define MA_LOG_H

#include <QFile>

class ma_log : public QFile
{
    Q_OBJECT
public:
    explicit ma_log(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // MA_LOG_H
