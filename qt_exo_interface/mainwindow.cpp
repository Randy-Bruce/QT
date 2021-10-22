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



void MainWindow::on_pushButtonLinux_clicked()
{
    ui->textEditTexteEvenement->append("bouton Linux");
}

void MainWindow::on_pushButtonWindows_clicked()
{
    ui->textEditTexteEvenement->append("bouton Windows");
}

void MainWindow::on_pushButtonOS_clicked()
{
    ui->textEditTexteEvenement->append("bouton OS");
}

void MainWindow::on_radioButtonLinux_clicked()
{
    ui->textEditTexteEvenement->append("radio Linux");
}

void MainWindow::on_radioButtonWindows_clicked()
{
    ui->textEditTexteEvenement->append("radio Windows");
}

void MainWindow::on_radioButtonOS_clicked()
{
    ui->textEditTexteEvenement->append("radio OS");
}

void MainWindow::on_checkButtonLinux_stateChanged(int arg1)
{
    if(arg1 == 0){
        ui->textEditTexteEvenement->append("Linux decoche");
    }else{
         ui->textEditTexteEvenement->append("Linux coche");
    }

}

void MainWindow::on_checkButtonWindows_stateChanged(int arg1)
{
    if(arg1 == 0){
        ui->textEditTexteEvenement->append("Windows decoche");
    }else{
         ui->textEditTexteEvenement->append("Windows coche");
    }
}

void MainWindow::on_checkButtonOS_stateChanged(int arg1)
{
    if(arg1 == 0){
        ui->textEditTexteEvenement->append("OS decoche");
    }else{
         ui->textEditTexteEvenement->append("OS coche");
    }
}


void MainWindow::on_lineEditCode_textChanged(const QString &arg1)
{
    ui->textEditTexteEvenement->append(arg1);
}

void MainWindow::on_DifferentChoix_currentIndexChanged(const QString &arg1)
{
    ui->textEditTexteEvenement->append(arg1);
}
