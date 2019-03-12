#ifndef REGESTRATION_H
#define REGESTRATION_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include <QPalette>

namespace Ui {
class Regestration;
}

class Regestration : public QDialog
{
    Q_OBJECT

public:
    explicit Regestration(QWidget *parent = nullptr);
    ~Regestration();
    QSqlDatabase myDb=QSqlDatabase::addDatabase("QSQLITE");

private slots:
    void on_Regestration_accepted();

    void on_pushButtonLogin_clicked();

    void on_pushButtonBack_clicked();

    void on_checkBoxLicence_stateChanged(int arg1);

private:
    Ui::Regestration *ui;
};

#endif // REGESTRATION_H
