#include "parameters.h"

using namespace s21;

GraphParams::GraphParams(QSize size)
    : width(size.width())
    , height(size.height())
    , graph_width(size.width() - left_indent - right_indent)
    , graph_height(size.height() - top_indent - bottom_indent)
    {}

qreal GraphParams::XToImageCords(double x) const noexcept
{
    return (x * x_factor) + dx;
}

qreal GraphParams::YToImageCords(double y) const noexcept
{
    return (y * y_factor) + dy;
}

double GraphParams::XToDataCords(qreal x) const noexcept
{
    return (x - dx) / x_factor;
}

double GraphParams::YToDataCords(qreal y) const noexcept
{
    return (y - dy) / y_factor;
}

void GraphParams::Resize(qreal w, qreal h)
{
    height = h;
    width = w;

    qreal gw = w - left_indent - right_indent;
    qreal gh = h - top_indent - bottom_indent;

    qreal dw = graph_width / gw;
    qreal dh = graph_height / gh;

    x_factor /= dw;
    y_factor /= dh;
    dx /= dw;
    dy = (dy - graph_height) / dh + gh;

    graph_height = gh;
    graph_width = gw;
}

void GraphParams::SetMinMax(qreal min_x, qreal max_x, qreal min_y, qreal max_y)
{
    SetYMinMax(min_y, max_y);
    SetXMinMax(min_x, max_x);
}

void GraphParams::SetYMinMax(qreal min_y, qreal max_y)
{
    std::cout << "SetYMinMax " << min_y << " " << max_y << std::endl;
    qreal qy = y_max - y_min;
    y_min = min_y;
    y_max = max_y;
    qreal fy = qy / (y_max - y_min);
    y_factor *= fy;
    dy = (dy - graph_height) * fy + graph_height;
    SetDy(dy);
}

void GraphParams::SetXMinMax(qreal min_x, qreal max_x)
{
    std::cout << "SetXMinMax " << min_x << " " << max_x << std::endl;
    qreal qx = x_max - x_min;
    x_min = min_x;
    x_max = max_x;
    qreal fx = qx / (x_max - x_min);
    x_factor *= fx;
    dx *= fx;
    SetDx(dx);
}

void GraphParams::AddMinMax(qreal min_x, qreal max_x, qreal min_y, qreal max_y)
{
    std::cout << "add " << min_x << " " << max_x << " " << min_y << " " << max_y << std::endl;
    std::cout << "2 add" << x_max << ' ' << x_min << '\n';
    if (x_max - x_min <= 0)
    {
        x_max = max_x;
        x_min = min_x;
    }
    else if (max_x > x_max || min_x < x_min)
    {
        SetXMinMax(min_x, max_x);
    }
    if (y_max - y_min <= 0)
    {
        y_max = max_y;
        y_min = min_y;
    }
    else if (max_y > y_max || min_y < y_min)
    {
        SetYMinMax(min_y, max_y);
    }
}

void GraphParams::SetDx(qreal candidate)
{
    dx = std::max(std::min(candidate, -1.0 * x_min * x_factor), graph_width - x_max * x_factor);
}

void GraphParams::SetDy(qreal candidate)
{
    dy = std::min(std::max(candidate, graph_height - y_min * y_factor), -1.0 * y_max * y_factor);
}

void GraphParams::SetFactors()
{
    x_factor = graph_width / (x_max - x_min);
    dx = -1.0 * x_min * x_factor;

    y_factor = graph_height / (y_min - y_max);
    dy = graph_height - y_min * y_factor;
}

QSize GraphParams::GraphSize() const noexcept
{
    return QSize(graph_width, graph_height);
}

qreal GraphParams::Bottom() const noexcept
{
    return height - bottom_indent;
}
qreal GraphParams::Top() const noexcept
{
    return top_indent;
}
qreal GraphParams::Left() const noexcept
{
    return left_indent;
}
qreal GraphParams::Right() const noexcept
{
    return width - right_indent;
}

QSize GraphParams::Size() const noexcept
{
    return QSize(width, height);
}


void GraphParams::Move(qreal x, qreal y)
{
    SetDx(dx + x);
    SetDy(dy + y);
}

void GraphParams::WheelScale(qreal scale_factor, QPointF cursor_pos)
{
    qreal pos_x = cursor_pos.x() - left_indent;
    qreal pos_y = cursor_pos.y() - top_indent;

    x_factor *= scale_factor;
    y_factor *= scale_factor;

    SetDx(pos_x - scale_factor * (pos_x - dx));
    SetDy(pos_y - scale_factor * (pos_y - dy));
}


