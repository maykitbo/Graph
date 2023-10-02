#include "graph.h"

using namespace s21;


Graph::Graph(GraphParams &params,
            GraphStyle &style,
            const QString &name,
            const QPen &graph_pen_,
            const QPen &points_pen,
            QImage::Format format)
    : VirtualLayer(params, style, name, format)
    , points_pen_(points_pen)
    , graph_pen_(graph_pen_)
    {}

Graph::Graph(GraphParams &params,
            GraphStyle &style,
            const QString &name,
            const std::vector<std::pair<double, double>> &data,
            const QPen &graph_pen_,
            const QPen &points_pen,
            QImage::Format format)
    : VirtualLayer(params, style, name + " [" + QString::number(data.size()) + "]", params.GraphSize(), format)
    , points_pen_(points_pen)
    , graph_pen_(graph_pen_)
    , data_(data)
{
    InitFrames();
    MinMax();
}

Graph::Graph(GraphParams &params,
            GraphStyle &style,
            const QString &name,
            std::vector<std::pair<double, double>> &&data,
            const QPen &graph_pen_,
            const QPen &points_pen,
            QImage::Format format)
    : VirtualLayer(params, style, name + " [" + QString::number(data.size()) + "]", params.GraphSize(), format)
    , points_pen_(points_pen)
    , graph_pen_(graph_pen_)
    , data_(std::move(data))
{
    InitFrames();
    MinMax();
}

void Graph::MinMax()
{
    if (data_.empty())
        return;
    min_x_ = data_.front().first;
    max_x_ = data_.back().first;
    auto yminmax = std::minmax_element(data_.begin(), data_.end(),
        [] (const std::pair<double, double> &p1, const std::pair<double, double> &p2)
        {
            return p1.second < p2.second;
        });
    min_y_ = yminmax.first->second;
    max_y_ = yminmax.second->second;
}


void Graph::Drawing()
{
    painter_.begin(&image_);
    image_.fill(Qt::transparent);

    std::vector<QPointF> points;

    if (data_.empty())
        return;

    unsigned step = p_.GraphStep(data_.size());
    points.reserve(data_.size() / step);
    for (unsigned i = 0; i < data_.size(); i += step)
    {
        points.emplace_back(p_.XToImageCords(data_[i].first),
                            p_.YToImageCords(data_[i].second));
    }
    
    if (draw_lines_)
    {
        painter_.setPen(graph_pen_);
        painter_.drawPolyline(points.data(), points.size());
    }
    if (draw_points_)
    {
        painter_.setPen(points_pen_);
        painter_.drawPoints(points.data(), points.size());
    }
    painter_.end();
}

void Graph::DrawingPoints(bool draw_points)
    { draw_points_ = draw_points; }

void Graph::DrawingLines(bool draw_lines)
    { draw_lines_ = draw_lines; }

void Graph::SetPointsColor(QColor color)
    { points_pen_.setColor(color); }

void Graph::SetGraphColor(QColor color)
    { graph_pen_.setColor(color); }

void Graph::SetDrawPoints(bool draw_points)
    { draw_points_ = draw_points; }

QColor Graph::GetGraphColor() const noexcept
    { return graph_pen_.color(); }

