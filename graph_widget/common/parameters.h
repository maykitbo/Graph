#pragma once

#include <QSize>
#include <QDateTime>
#include <limits>
#include <QPointF>

#include <iostream>

namespace s21 {

struct MinMax
{
    qreal x_min{0};
    qreal x_max{0};
    qreal y_min{0};
    qreal y_max{0};
};

class GraphParams
{
    public:
        unsigned GraphStep(unsigned size) const noexcept;

        QSize GraphSize() const noexcept;

        qreal XToImageCords(double x) const noexcept;
        qreal YToImageCords(double y) const noexcept;
        double XToDataCords(qreal x) const noexcept;
        double YToDataCords(qreal y) const noexcept;

        // void SetDx(qreal dx);
        // void SetDy(qreal dy);

        void SetMinMax(qreal min_x, qreal max_x, qreal min_y, qreal max_y);

        void Resize(qreal w, qreal h);
        void SetFactors();

        qreal Bottom() const noexcept;
        qreal Top() const noexcept;
        qreal Left() const noexcept;
        qreal Right() const noexcept;

        QSize Size() const noexcept;

        void Move(qreal x, qreal y);
        void WheelScale(qreal scale_factor, QPointF cursor_pos);

    private:
        // QSize size;
        qreal dx{0};
        qreal dy{0};

        qreal x_min{0};
        qreal x_max{0};
        qreal y_min{0};
        qreal y_max{0};

        unsigned max_point_on_one_graph{30000};

        qreal x_factor;
        qreal y_factor;

        qreal width{1};
        qreal height{1};
        qreal graph_width{1};
        qreal graph_height{1};

        qreal top_indent{10};
        qreal bottom_indent{30};
        qreal left_indent{50};
        qreal right_indent{10};

        void SetDx(qreal dx);
        void SetDy(qreal dy);

    
};


} // namespace s21
