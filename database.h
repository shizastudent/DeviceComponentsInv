#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include "dependencies.h"

class database:public QObject
{
public:
    database();
    bool openConnection();
    bool closeConnection();
    QString CheckUserRole(QString login);
public slots:
    bool authorizathion(QString login, QString password);

private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "mydb");
    bool conn = db.open();
};

#endif // DATABASE_H
