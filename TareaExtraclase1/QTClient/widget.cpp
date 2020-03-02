#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    QFile file("/home/emanuel/Desktop/CE2103-Algoritmos-Estructuras-Datos2/TareaExtraclase1/QTClient/GraphFile");

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "File no open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_clicked()
{


}
