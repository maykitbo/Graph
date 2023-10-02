#include "background_layer_frame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    background_layer_frame w;
    w.show();
    return a.exec();
}
