#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "regestration.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/pix1.jpg");
    ui->labelPic->setPixmap(pix.scaled(120,150,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    LogIn login;
    login.setModal(true);
    login.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Regestration regestration;
    regestration.setModal(true);
    regestration.exec();
}
