#include <QApplication>

#include "widget_frame/widget_frame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // s21::initializeLibrary();

    Graph::WidgetFrame w;

    w.show();


    Graph::data_t data1{{0, 0}, {1, 1}, {2, 2}, {4, 3}};
    Graph::data_t data2{{-1, 3}, {1, 1}, {2, 2}, {3, 3}};
    Graph::data_t data3{{0, 0}, {1, -2}, {2, 2}, {3, 3}};

    w.GetFrame()->GetBackground()->SetXTextFunc(Graph::Background::NumberFormat);

    w.AddGraph(data1, "data1", true);
    w.AddGraph(data2, "data2", true);
    w.AddGraph(data3, "data3", false);


    // QPixmap pixmap("://images/visible.png");
    // std::cout << pixmap.width() << " " << pixmap.height() << "\n";
    // QImage image = pixmap.toImage();
    // image.save("v.png");

    return a.exec();
}
