#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <QSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>


namespace Ui {
class LogIn;
}

class LogIn : public QDialog
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();
    QSqlDatabase myDb=QSqlDatabase::addDatabase("QSQLITE");



private slots:
    void on_pushButtonClose_clicked();
    void on_pushButton_clicked();

private:
    Ui::LogIn *ui;
};

#endif // LOGIN_H
