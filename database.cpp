#include "database.h"

database::database()
{

}

bool database::openConnection()
{
    return db.open();
}

QString database::CheckUserRole(QString login)
{
    QString role;
    if (login=="admin")
    {
        role="admin";
        return role;
    }
    else
    {
        if (login=="checkman")
    {
        role="checkman";
        return role;
    }
        else
        {
            role="NO";
            return role;
        }
    }


}

bool database::authorizathion(QString login, QString password)
{
    if ((login=="admin"&password=="admin")||(login=="checkman"&password=="checkman")){
        return true;
    }
    else
        return false;

}
