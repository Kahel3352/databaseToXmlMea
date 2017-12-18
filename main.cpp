#include <QCoreApplication>
#include <iostream>
#include <QtSql>

using namespace std;

/**
 * @brief Vérifie les paramètres passés au programme
 * @return true si les paramètres sont bons
 */
bool checkArgs(int argc);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //on vérifie que l'utilisateur à rentrer les paramètres
    if(!checkArgs(argc))
    {
        cout<<"Bad syntax: dataabseToXmlMea [host] [username] [password] [database] [filename]"<<endl;
        cout<<"Argc: "<<argc<<endl;
    }
    else
    {
        QString host = argv[1];
        QString username = argv[2];
        QString password = argv[3];
        QString database = argv[4];
        QString fileName = argv[5];
        cout<<"--Connecting to "<<host.toStdString()<<":"<<database.toStdString()<<endl;
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QMYSQL3");
        db.setHostName(host);
        db.setDatabaseName(database);
        db.setUserName(username);
        db.setPassword(password);
        if(!db.open())
            cout<<"Error connection database: "<<db.lastError().text().toStdString()<<endl;
        cout<<"--Generating "<<fileName.toStdString()<<endl;
    }
    return 0;
}

bool checkArgs(int argc)
{
    //host
    //username
    //password
    //database
    //nom du fichier
    return argc == 6;
}
