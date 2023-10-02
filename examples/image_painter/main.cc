#include "image_painter/image_painter.h"

int main(int argc, char *argv[])
{
    s21::ImagePainter painter(QSize(1000, 1000), argc, argv);

    s21::Graph::data_t data1 = {
        {0, 0},
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 4}
    };
    s21::Graph::data_t data2 = {
        {0, 0},
        {1, 1},
        {2, 0},
        {3, -1},
        {4, 0},
        {5, 1}
    };
    s21::Graph::data_t data3 = {
        {-2, 2},
        {0, 2},
        {2, 2},
        {4, 2},
    };
    s21::Graph::data_t data4 = {
        {0, 0},
        {3, 7},
        {4, -1},
        {7, -2},
    };
    painter.ReserveGraphs(4);
    painter.AddGraph(data1, "data1");
    painter.AddGraph(data2, "data2", QPen(QColor(0, 255, 0)));
    painter.AddGraph(std::move(data3), "data3");
    painter.AddGraph(std::move(data4), "data4");

    painter.GetBackground().SetXTextFunc(s21::Background::NumberFormat);

    painter.SavePng("test.png");

    return 0;
}