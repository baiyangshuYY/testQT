#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QStackedWidget>

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
    void onButtonClicked();
    void onTimerTimeout();
    void on_buttonPage1_clicked();
    void on_buttonPage2_clicked();

private:
    Ui::MainWindow *ui;

private:
    QPushButton *button;

    QTimer      *timer;
    QStackedWidget *stackedWidget;
};
#endif // MAINWINDOW_H
