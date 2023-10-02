#include "graph.h"

using namespace s21;


// GraphLayer::GraphLayer(GraphParams &params,
//             GraphStyle &style,
//             const QString &name,
//             const QPen &graph_pen_,
//             const QPen &points_pen,
//             QImage::Format format)
//     : VirtualLayer(params, style, name, format)
//     , points_pen_(points_pen)
//     , graph_pen_(graph_pen_)
// {
//     InitFrames();
// }

GraphLayer::GraphLayer(GraphParams &params,
            GraphStyle &style,
            const QString &name,
            const QPen &graph_pen_,
            const std::vector<std::pair<double, double>> &data,
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

GraphLayer::GraphLayer(GraphParams &params,
            GraphStyle &style,
            const QString &name,
            const QPen &graph_pen_,
            std::vector<std::pair<double, double>> &&data,
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

void GraphLayer::MinMax()
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

void GraphLayer::InitFrames()
{
    name_label_->setStyleSheet("QLabel { color : " + graph_pen_.color().name() + "; }");
    // name_label_->setText(name_ + " [" + QString::number(data_.size()) + "]");
    name_label_->setCursor(Qt::OpenHandCursor);

    remove_button_ = new QPushButton("X", this);
    remove_button_->setMaximumSize(20, 20);
    h_layout_->addWidget(remove_button_);
    connect(remove_button_, &QPushButton::clicked, this, &VirtualLayer::Remove);

    visible_button_ = new QRadioButton("", this);
    visible_button_->setMaximumSize(20, 20);
    visible_button_->setChecked(true);
    h_layout_->insertWidget(0, visible_button_);
    visible_button_->setChecked(true);
    connect(visible_button_, &QRadioButton::toggled, this, [&] (bool checked)
    {
        emit ChangeVisible(checked);
        emit ReDraw();
    });

    CreateSettingsFrame();
}


void GraphLayer::Drawing()
{
    if (!visible_)
        return;

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


GraphLayer::~GraphLayer()
{
    delete remove_button_;
    delete visible_button_;
}


void GraphLayer::DrawingPoints(bool draw_points)
    { draw_points_ = draw_points; }

void GraphLayer::DrawingLines(bool draw_lines)
    { draw_lines_ = draw_lines; }

void GraphLayer::SetPointsColor(QColor color)
    { points_pen_.setColor(color); }

void GraphLayer::SetGraphColor(QColor color)
    { graph_pen_.setColor(color); }

void GraphLayer::SetRemovable(bool removable)
    { remove_button_->setEnabled(removable); }

bool GraphLayer::Visible() const noexcept
    { return visible_button_->isChecked(); }

void GraphLayer::SetDrawPoints(bool draw_points)
    { draw_points_ = draw_points; }

QColor GraphLayer::GetGraphColor() const noexcept
    { return graph_pen_.color(); }

void GraphLayer::SetBackgroundColor(QColor color)
    { backgrpund_color_ = color; }

