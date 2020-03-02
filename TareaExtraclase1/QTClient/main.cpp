#include "widget.h"
#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    std::cout<<"Holi todo listo"<<std::endl;
    return a.exec();
}
