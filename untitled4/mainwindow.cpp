#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qwidget.h>
#include <QFile>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QtUiTools/QUiLoader>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer)
{
    ui->setupUi(this);
    button=ui->pushButtonTest;
    connect(button,&QPushButton::clicked,this, &MainWindow::onButtonClicked);
    connect(timer,&QTimer::timeout,this, &MainWindow::onTimerTimeout);
    QWidget *page1=new QWidget;
    QFile file1("dialog.ui");
    file1.open(QFile::ReadOnly);
    QUiLoader loader;
    QWidget *loadPage1=loader.load(&file1,page1);
    file1.close();
    ui->stackedWidget->addWidget(loadPage1);

    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onButtonClicked()
{
    button->setEnabled(false);
  timer->start(10000);
}
void MainWindow::onTimerTimeout()
{
 button->setEnabled(true);
 timer->stop();
}

