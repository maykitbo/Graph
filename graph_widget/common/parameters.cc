#include "parameters.h"

using namespace s21;

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
    qreal qx = x_max - x_min;
    qreal qy = y_max - y_min;

    x_min = min_x;
    x_max = max_x;
    y_min = min_y;
    y_max = max_y;

    qreal fx = qx / (x_max - x_min);
    qreal fy = qy / (y_max - y_min);

    x_factor *= fx;
    y_factor *= fy;

    dx *= fx;
    dy = (dy - graph_height) * fy + graph_height;

    SetDx(dx);
    SetDy(dy);
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

unsigned GraphParams::GraphStep(unsigned size) const noexcept
{
    return 1u + size / max_point_on_one_graph;
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


