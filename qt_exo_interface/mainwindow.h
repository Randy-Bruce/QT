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
    void on_checkLinux_clicked(bool checked);

    void on_checkWindows_clicked(bool checked);

    void on_checkOS_clicked(bool checked);

    void on_radioLinux_clicked();

    void on_radioWindows_clicked();

    void on_radioOS_clicked();

    void on_pushButtonLinux_clicked();

    void on_pushButtonWindows_clicked();

    void on_pushButtonOS_clicked();

    void on_checkButtonLinux_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
