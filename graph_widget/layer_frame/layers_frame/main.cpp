#include "layers_frame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    layers_frame w;
    w.show();
    return a.exec();
}
