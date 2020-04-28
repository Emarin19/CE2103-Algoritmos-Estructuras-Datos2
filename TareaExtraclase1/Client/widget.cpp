#include "widget.h"
#include "./ui_widget.h"
#include <iostream>
#include "socket.h"
#include <QDebug>
#include <QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    client = new Socket();
    ui->setupUi(this);
    QString qstr = QString::fromStdString(client->readMsg());
    ui->plainTextEdit->setPlainText(qstr);
}

Widget::~Widget()
{
    client->sendMsg("stop");
    delete ui;
}


void Widget::on_Dijkstra_clicked()
{
    ui->plainTextEdit->setPlainText("Can't calculate the shortest path");
}
