#include "arbol.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Arbol w;
    w.show();

    return a.exec();
}
