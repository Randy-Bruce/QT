#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkButtonLinux_stateChanged(int arg1)
{
    if (arg1 == 1){
        ui->textEditTexteEvenement->setText("Linux Coché");
    }else{
        ui->textEditTexteEvenement->setText("Linux Décoché");
    }
}
