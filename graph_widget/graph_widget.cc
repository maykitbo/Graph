#include "graph_widget.h"

using namespace s21;

GraphWidget::GraphWidget(QWidget *parent)
    : QWidget(parent)
    , layers_frame_(new LayersFrame(p_, s_, this))
{
    connect(layers_frame_, &LayersFrame::ReDraw, this, [&] ()
    {
        update();
    });
    setMinimumHeight(s_.min_height);
    setMinimumWidth(s_.min_width);
}


void GraphWidget::resizeEvent(QResizeEvent *event)
{
    const auto &size = event->size();

    p_.Resize(size.width(), size.height());

    QWidget::resizeEvent(event);
    layers_frame_->Resize();
    update();
}

void GraphWidget::paintEvent(QPaintEvent *event)
{
    QPainter(this).drawImage(0, 0, *layers_frame_->GetBackground()->GetImage());
    layers_frame_->ForVisible([&] (GraphLayer *layer)
    {
        QPainter(this).drawImage(p_.Left(), p_.Top(), *layer->GetImage());
    });
    QWidget::paintEvent(event);
}

void GraphWidget::AddGraph(std::vector<std::pair<double, double>> &data, const QString &name, bool points)
{
    layers_frame_->AddGraph(name, data, points);
    update();
}


void GraphWidget::wheelEvent(QWheelEvent *event)
{
    qreal scale_factor = 1.0;
    if (event->angleDelta().y() > 0)
    {
        ++scale_;
        scale_factor = s_.wheel_scale_factor;
    }
    else
    {
        if (scale_ == 0)
        {
            return QWidget::wheelEvent(event);
        }
        --scale_;
        scale_factor = 1.0 / s_.wheel_scale_factor;
    }

    p_.WheelScale(scale_factor, event->position());

    layers_frame_->Draw();
    update();
    QWidget::wheelEvent(event);
}


void GraphWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (mouse_pressed_)
    {
        // p_.SetDx(p_.dx - mouse_pos_.x() + event->pos().x());
        // p_.SetDy(p_.dy - mouse_pos_.y() + event->pos().y());
        p_.Move(event->pos().x() - mouse_pos_.x(),
                event->pos().y() - mouse_pos_.y());
        layers_frame_->Draw();
        update();
        mouse_pos_ = event->pos();
    }
    QWidget::mouseMoveEvent(event);
}

void GraphWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        mouse_pressed_ = true;
        mouse_pos_ = event->pos();
    }
    QWidget::mousePressEvent(event);
}

void GraphWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        mouse_pressed_ = false;
    }
    QWidget::mouseReleaseEvent(event);
}


void GraphWidget::Clear()
{
    scale_ = 0;
    layers_frame_->Clear();
    update();
}

