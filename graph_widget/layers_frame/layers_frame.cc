#include "layers_frame.h"

using namespace s21;

LayersFrame::LayersFrame(GraphParams &params, GraphStyle &style, QWidget *parent)
    : QScrollArea(parent)
    , p_(params)
    , s_(style)
    , widget_(new QFrame(this))
    // , scroll_area_(new QScrollArea(this))
{
    setAcceptDrops(true);
    layout_ = new QVBoxLayout(widget_);
    layout_->setSpacing(4);
    background_ = new BackgroundLayer(p_, s_, "Background");
    layout_->addWidget(background_);
    // setWidget(widget_);
    widget_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    // widget_->setFixedWidth(186);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    setWidgetResizable(true);
    setWidget(widget_);

    // widget_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout_->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

void LayersFrame::Draw()
{
    // std::cout << "LayersFrame::Draw\n";
    background_->SetShowText(visible_count_ != 0);
    background_->Drawing();
    ForVisible([&] (GraphLayer *layer)
    {
        layer->Drawing();
    });

}

void LayersFrame::ForGraphLayers(const std::function<void(GraphLayer*)> &func)
{
    for (unsigned i = 1; i < layout_->count() - 1; ++i)
    {
        GraphLayer *layer = dynamic_cast<GraphLayer*>(layout_->itemAt(i)->widget());
        if (layer != nullptr)
            func(layer);
    }
}

void LayersFrame::ForVisible(const std::function<void(GraphLayer*)> &func)
{
    ForGraphLayers([&] (GraphLayer *layer)
    {
        if (layer->Visible())
            func(layer);
    });
}

void LayersFrame::AddGraph(const QString &name,
            std::vector<std::pair<double, double>> &data, bool points)
{
    QPen pen(s_.colors.back(), s_.graph_width);
    QColor color = s_.colors.back();
    color.setHsl(color.hslHue() > 180 ? color.hslHue() - 180 : color.hslHue() + 180, color.hslSaturation(), color.lightness());
    QPen points_pen(color, s_.point_radius);
    s_.colors.pop_back();

    GraphLayer *ptr = new GraphLayer(p_, s_, name, pen, std::move(data), points_pen);
    ptr->SetDrawPoints(points);

    layout_->insertWidget(layout_->count() - 1, ptr);
    updateGeometry();


    ptr->NameLabel()->installEventFilter(this);

    ProcessMinMax();

    if (layout_->count() == 3)
    {
        // scale_ = 0;
        p_.SetFactors();
        ptr->SetRemovable(false);
    }



    Draw();
    ++visible_count_;

    connect(ptr, &GraphLayer::Remove, this, [&] ()
    {
        GraphLayer *sender = dynamic_cast<GraphLayer*>(QObject::sender());
        QColor color = sender->GetGraphColor();
        s_.colors.push_back(color);
        layout_->removeWidget(sender);
        delete sender;
        ProcessMinMax();
        emit GraphRemoved();
        emit ReDraw();
    });
    connect(ptr, &GraphLayer::ReDraw, this, &LayersFrame::ReDraw);
    connect(ptr, &GraphLayer::ChangeVisible, this, [&] (bool visible)
    {
        visible_count_ += visible ? 1 : -1;
        ProcessMinMax();
        Draw();
    });

    emit ReDraw();
}

void LayersFrame::ProcessMinMax()
{
    qreal min_x = std::numeric_limits<qreal>::max();
    qreal max_x = std::numeric_limits<qreal>::min();
    qreal min_y = std::numeric_limits<qreal>::max();
    qreal max_y = std::numeric_limits<qreal>::min();
    ForVisible([&] (GraphLayer *layer)
    {
            min_x = std::min(min_x, layer->MinX());
            max_x = std::max(max_x, layer->MaxX());
            min_y = std::min(min_y, layer->MinY());
            max_y = std::max(max_y, layer->MaxY());
    });
    p_.SetMinMax(min_x, max_x, min_y, max_y);
}

void LayersFrame::Clear()
{
    while (layout_->count() > 2)
    {
        GraphLayer *layer = dynamic_cast<GraphLayer*>(layout_->itemAt(1)->widget());
        if (layer != nullptr)
        {
            layout_->removeWidget(layer);
            delete layer;
        }
    }
    s_.colors =
    {
        QColor(149, 149, 149),
        QColor(92, 108, 124),
        QColor(174, 124, 124),
        QColor(132, 169, 141),
        QColor(255, 0, 0),
    };
}

void LayersFrame::Resize()
{
    background_->Resize(p_.Size());
    ForVisible([&] (GraphLayer *layer)
    {
        layer->Resize(p_.GraphSize());
    });
}


bool LayersFrame::eventFilter(QObject *object, QEvent *event)
{
    if (object == nullptr)
        return false;

    QLabel *name_label = qobject_cast<QLabel*>(object);
    if (name_label)
    {
        QMouseEvent *mouseEvent = nullptr;

        switch (event->type())
        {
        case QEvent::MouseButtonPress:
            if (LablePressed(name_label, event))
                return true;
            break;
        case QEvent::MouseButtonRelease:
            if (LableReleased(name_label, event))
                return true;
            break;
        case QEvent::MouseMove:
            if (LableMove(name_label, event))
                return true;
            break;
        }
    }
    return QObject::eventFilter(object, event);
}

bool LayersFrame::LablePressed(QLabel *label, QEvent *event)
{
    if (dynamic_cast<QMouseEvent*>(event)->button() == Qt::LeftButton)
    {
        dragged_layer_ = static_cast<GraphLayer*>(label->parentWidget());
        label->setCursor(Qt::ClosedHandCursor);
        return true;
    }
    return false;
}

bool LayersFrame::LableReleased(QLabel *label, QEvent *event)
{
    if (static_cast<QMouseEvent*>(event)->button() == Qt::LeftButton)
    {
        label->setCursor(Qt::OpenHandCursor);
        dragged_layer_ = nullptr;
        return true;
    }
    return false;
}

bool LayersFrame::LableMove(QLabel *label, QEvent *event)
{
    if (dragged_layer_ == nullptr)
        return false;

    QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
    auto pos = mapFromGlobal(mouse_event->globalPos());

    int k = layout_->indexOf(dragged_layer_);

    if (k < layout_->count() - 2)
    {
        auto pos_under = layout_->itemAt(k + 1)->widget()->pos();
        if (pos.y() > pos_under.y() + 2 * dragged_layer_->height() / 3)
        {
            layout_->removeWidget(dragged_layer_);
            layout_->insertWidget(k + 1, dragged_layer_);
            emit ReDraw();
            return true;
        }
    }
    if (k > 1)
    {
        auto pos_above = layout_->itemAt(k - 1)->widget()->pos();
        if (pos.y() < pos_above.y() + dragged_layer_->height() / 3)
        {
            layout_->removeWidget(dragged_layer_);
            layout_->insertWidget(k - 1, dragged_layer_);
            emit ReDraw();
            return true;
        }
    }

    return false;
}

LayersFrame::~LayersFrame()
{
    ForGraphLayers([&] (GraphLayer *layer)
    {
        layout_->removeWidget(layer);
        delete layer;
    });
    delete background_;
    delete layout_;
    delete widget_;
}

