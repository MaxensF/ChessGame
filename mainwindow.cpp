#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <iostream>
#include <QGraphicsView>
#include <QLabel>
#include <QStyle>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{




    ui->setupUi(this);

    // cutting the edges
    ui->Button->setFlat(true);
    //no focus
    ui->Button->setFocusPolicy(Qt::NoFocus);

    ui->Button->setIcon(QPixmap("://Pieces/BlackBishop.png"));
    ui->Button->setIcon(QPixmap("://Pieces/WhiteBishop.png"));

     ui->Button->setFixedHeight(42);
     ui->Button->setFixedWidth(42);
     ui->Button->setIconSize(QSize(42,42));
    // no edges when clicked
    ui->Button->setStyleSheet("QPushButton:flat:pressed { border: none; };");












}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_Button1_2_clicked()
{
    std::cout<<"abvzj"<<std::endl;
}
