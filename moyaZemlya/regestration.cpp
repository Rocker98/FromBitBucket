#include "regestration.h"
#include "ui_regestration.h"

Regestration::Regestration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Regestration)
{
    ui->setupUi(this);
    myDb.setDatabaseName("C:/Users/Home/Desktop/users.db");
    if(!myDb.open())
        qDebug()<<"Error opening...";
    else
        qDebug()<<"Cenected, finaly!";
}

Regestration::~Regestration()
{

    qDebug()<<"Close DB";
    delete ui;
    myDb.close();

}


void Regestration::on_Regestration_accepted()
{
    ui->pushButtonLogin->setEnabled(1);
}

void Regestration::on_pushButtonLogin_clicked()
{
    if(myDb.open())
    {
        QPalette pal,palGo;
        pal.setColor(QPalette::Base,Qt::yellow);
        palGo.setColor(QPalette::Base,Qt::white);
        qDebug()<<"Open DB";
        QString sQuery ="INSERT INTO users ([name],[surname],[email],[phone],[password],[isEmploee])" \
                        " VALUES (:s_name,:s_surname,:s_email,:s_phone,:s_password,:s_isEmploee)";

        QString s_name,s_surname,s_email,s_phone,s_password,s_repeatPass;

        s_name=ui->lineName->text();
        if(s_name.isEmpty())
        {
            ui->lineName->setPalette(pal);
            ui->labelIfEmpty->setText("Field is empty. Please fill it.");
            return;
        }
        else
        {
            ui->lineName->setPalette(palGo);
            ui->labelIfEmpty->setText("");
        }
        s_surname=ui->lineSurname->text();
        if(s_surname.isEmpty())
        {
            ui->lineSurname->setPalette(pal);
            ui->labelIfEmpty->setText("Field is empty. Please fill it.");
            return;
        }
        else
        {
            ui->lineName->setPalette(palGo);
            ui->labelIfEmpty->setText("");
        }
        s_email=ui->lineEmail->text();
        if(s_email.isEmpty())
        {
            ui->lineEmail->setPalette(pal);
            ui->labelIfEmpty->setText("Field is empty. Please fill it.");
            return;
        }
        else
        {
            ui->lineName->setPalette(palGo);
            ui->labelIfEmpty->setText("");
        }
        s_phone=ui->linePhone->text();
        if(s_phone.isEmpty())
        {
            ui->linePhone->setPalette(pal);
            ui->labelIfEmpty->setText("Field is empty. Please fill it.");
            return;
        }
        else
        {
            ui->lineName->setPalette(palGo);
            ui->labelIfEmpty->setText("");
        }
        s_password=ui->linePassword->text();
        if(s_password.isEmpty())
        {
            ui->linePassword->setPalette(pal);
            ui->labelIfEmpty->setText("Field is empty. Please fill it.");
            return;
        }
        else
        {
            ui->lineName->setPalette(palGo);
            ui->labelIfEmpty->setText("");
        }
        s_repeatPass=ui->lineRepeat->text();

        if(s_password!=s_repeatPass)
        {
            QMessageBox::about(this,"Warning","Passwordds are not equal!");
        }
        else
        {
            QSqlQuery qry;
            if(qry.exec("SELECT EXISTS(SELECT email FROM users WHERE email="+s_email+')'))
            {
                qDebug()<<"This email already exist!";
                return;
            }
            else
            {
                qry.prepare(sQuery);
                qry.bindValue(":s_name",s_name);
                qry.bindValue(":s_surname",s_surname);
                qry.bindValue(":s_email",s_email);
                qry.bindValue(":s_phone",s_phone.toLongLong());
                qry.bindValue(":s_password",s_password.toLongLong());
                if(ui->checkBoxAsEmploee->isChecked())
                {
                    qry.bindValue(":s_isEmploee",1);
                }
                else
                    qry.bindValue(":s_isEmploee",0);
            }

            if(qry.exec())
            {
                qDebug()<<"Recorded";
                this->close();
            }

            qDebug()<<"Closind DB recording";
            myDb.close();

        }
    }
}

void Regestration::on_pushButtonBack_clicked()
{
     this->close();
}

void Regestration::on_checkBoxLicence_stateChanged(int arg1)
{
    if(arg1==2)
    ui->pushButtonLogin->setEnabled(1);
    else ui->pushButtonLogin->setEnabled(0);
}


