#include "database.h"
#include <QDebug>
database::database()
{
    //openConnection();

}

bool database::openConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("192.168.0.2");
    db.setDatabaseName("mydb");
    db.setUserName("test");
    db.setPassword("Shoroh123");
    return db.open();
}











