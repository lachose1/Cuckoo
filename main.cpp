#include <QtGui/QApplication>
#include "cuckoo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cuckoo w;
    w.show();

    return a.exec();
}
