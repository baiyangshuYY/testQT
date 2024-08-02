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
   QPushButton * buttonTest=new QPushButton("test button",this);
      buttonTest->setGeometry(50, 50, 100, 30);
    button=ui->pushButtonTest;
    stackedWidget=ui->stackedWidget;
    QPushButton* btnSwitchToPage1=ui->pushButtonChangePage1;
    QPushButton* btnSwitchToPage2=ui->pushButtonChangePage2;

    connect(button,&QPushButton::clicked,this, &MainWindow::onButtonClicked);
    connect(btnSwitchToPage1,&QPushButton::clicked,this, &MainWindow::on_buttonPage1_clicked);
    connect(btnSwitchToPage2,&QPushButton::clicked,this, &MainWindow::on_buttonPage2_clicked);


    connect(timer,&QTimer::timeout,this, &MainWindow::onTimerTimeout);
    QWidget *page1=new QWidget;
        QUiLoader loader;
    QFile file1("G:\\QTCode\\QTGit\\untitled4\\dialog.ui");
    if(file1.open(QFile::ReadOnly))
  {    QWidget *loadPage1=loader.load(&file1,page1);
        file1.close();
        if(loadPage1);
        stackedWidget->addWidget(loadPage1);
    }



    QWidget *page2=new QWidget;
    QFile file2("G:\\QTCode\\QTGit\\untitled4\\dialog2.ui");
    file2.open(QFile::ReadOnly);

    QWidget *loadPage2=loader.load(&file2,page2);
    file2.close();
    stackedWidget->addWidget(loadPage2);
    int pageCount=stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(2);
     //ui->stackedWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onButtonClicked()
{

      ui->stackedWidget->setCurrentIndex(0);
    button->setEnabled(false);
  timer->start(10000);
}
void MainWindow::onTimerTimeout()
{
 button->setEnabled(true);
  ui->stackedWidget->setCurrentIndex(1);
 timer->stop();
}

void MainWindow::on_buttonPage1_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
      //ui->stackedWidget->show();
}

void MainWindow::on_buttonPage2_clicked()
{
   ui->stackedWidget->setCurrentIndex(3);
      // ui->stackedWidget->show();
}


