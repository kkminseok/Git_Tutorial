#include "diaglog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Diaglog w;
    w.show();

    return a.exec();
}
