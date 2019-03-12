#include "login.h"
#include "ui_login.h"

LogIn::LogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    myDb.setDatabaseName("C:/Users/Home/Desktop/users.db");
    if(!myDb.open())
    {
        qDebug()<<"Error opening...";
    }
    else
    {
        qDebug()<<"Conected, finaly!";
        myDb.close();
    }


}

LogIn::~LogIn()
{

    qDebug()<<"Close DB";
    delete ui;
}


void LogIn::on_pushButtonClose_clicked()
{
    this->close();
}

void LogIn::on_pushButton_clicked()
{
    if(!myDb.open())
    {
        qDebug()<<"Database is closed.";
    }
    else
    {
        QString email,password;
        email=ui->lineEmailLogin->text();
        password=ui->linePasswordLogin->text();

        QSqlQuery qry;
        if(qry.exec("SELECT * FROM users WHERE email='"+email+"'AND password='"+password+"'"))
        {
            if(qry.last())
            {
                qDebug()<<qry.value(1).toString();
            }
            else
            {
                 qDebug()<<"Oops..Wrong login or password.";
            }
        }
        else
        {
             qDebug()<<"Error opening query...";
        }
    }
}




