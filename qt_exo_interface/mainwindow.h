#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonLinux_clicked();

    void on_pushButtonWindows_clicked();

    void on_pushButtonOS_clicked();

    void on_checkButtonLinux_stateChanged(int arg1);

    void on_radioButtonLinux_clicked();

    void on_radioButtonWindows_clicked();

    void on_radioButtonOS_clicked();

    void on_checkButtonWindows_stateChanged(int arg1);

    void on_checkButtonOS_stateChanged(int arg1);


    void on_lineEditCode_textChanged(const QString &arg1);

    void on_DifferentChoix_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
