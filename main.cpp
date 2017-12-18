#include <QCoreApplication>
#include <iostream>
#include <QtSql>

using namespace std;

/**
 * @brief Vérifie les paramètres passés au programme
 * @return true si les paramètres sont bons
 */
bool checkArgs(int argc);

/**
 * @brief Récupère les noms des tables
 * @return Liste des noms des tables
 */
QStringList getTablesName();

/**
 * @brief Renvoie le script de création de la table
 * @param nom de la table
 * @return script de création de la table
 */
QString getCreateTable(QString tableName);

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
        //on récupère les paramètres
        QString host = argv[1];
        QString username = argv[2];
        QString password = argv[3];
        QString database = argv[4];
        QString fileName = argv[5];

        //on se connecte à la base de données
        cout<<"--Connecting to "<<host.toStdString()<<":"<<database.toStdString()<<endl;
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QMYSQL3");
        db.setHostName(host);
        db.setDatabaseName(database);
        db.setUserName(username);
        db.setPassword(password);
        if(!db.open())
            cout<<"Error connection database: "<<db.lastError().text().toStdString()<<endl;
        else
        {
            //on récupère la liste du nom des tables
            QStringList tableNames = getTablesName();



        }
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

QStringList getTablesName()
{
    QStringList tableNames;
    QSqlQuery queryShowTables;
    queryShowTables.exec("SHOW tables;");
    cout<<"Tables: "<<endl;
    while(queryShowTables.next())
    {
        tableNames.append(queryShowTables.value(0).toString());
    }

    return tableNames;
}


