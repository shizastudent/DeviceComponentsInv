#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include "dependencies.h"

class database:public QObject
{
public:
    database();


    bool openConnection();
    bool closeConnection();
    QSqlDatabase getDB();

    QString CheckUserRole(QString login);

    QSqlTableModel * getUsers();

    void updateUser(int id,QString login,QString password,QString Role);

    QSqlTableModel* getWarehouses();
    void addWarehouse(QString address, int area);
    void updateWarehouse(int id,QString address, int area);
    void deleteWarehouse(int id);


    QSqlTableModel* getComponents();
    void addComponent();
    void updateComponent();
    void deleteComponent(int id);


    QSqlTableModel* getDevices();


    QSqlTableModel* getWaybills();

    QSqlTableModel* getRepairers();



public slots:
    bool authorizathion(QString login, QString password);
    void addUser(QString login,QString password,QString Role);
    void deleteUser(int iduser);

private:





};

#endif // DATABASE_H
