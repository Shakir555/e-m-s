#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include "database.h"

void initializeDatabase() 
{
    QString dbPath = "employee.db";
    bool dbExists = QFile::exists(dbPath);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    if (!db.open()) 
    {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return;
    }
    if (!dbExists) 
    {
        QSqlQuery query;
        QString createTableQuery = R"(
            CREATE TABLE employees (
                id TEXT PRIMARY KEY,
                name TEXT NOT NULL,
                department TEXT NOT NULL,
                salary TEXT NOT NULL
            )
        )";
        if (!query.exec(createTableQuery)) 
        {
            qDebug() << "Failed to create table:" << query.lastError().text();
        } else 
        {
            qDebug() << "Table 'employees' created successfully!";
        }
    } 
    else 
    {
        qDebug() << "Database already exists.";
    }
    db.close();
}
