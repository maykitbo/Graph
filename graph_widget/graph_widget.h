#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGestureEvent>
#include <QWheelEvent>
#include <QtMath>
#include <QDateTime>
#include <QSpacerItem>

#include "common/style.h"
#include "common/parameters.h"
#include "layers_frame.h"


#include <algorithm>
#include <functional>

namespace s21 {

class GraphWidget : public QWidget
{
    friend class NamesFrame;
    Q_OBJECT

    public:
        GraphWidget(QWidget *parent = 0);
        virtual ~GraphWidget() = default;
        void AddGraph(std::vector<std::pair<double, double>> &data, const QString &name, bool points = false);
        void Clear();
        LayersFrame *GetLayersFrame() { return layers_frame_; }
    
    signals:
        void GraphRemoved(unsigned index);
    
    private:
        void paintEvent(QPaintEvent *event) override;
        void resizeEvent(QResizeEvent *event) override;
        void wheelEvent(QWheelEvent *event) override;
        void mouseMoveEvent(QMouseEvent *event) override;
        void mousePressEvent(QMouseEvent *event) override;
        void mouseReleaseEvent(QMouseEvent *event) override;

        GraphStyle s_;
        GraphParams p_;
    
        QPoint mouse_pos_{0, 0};
        bool mouse_pressed_;
        bool ready_{false};

        int scale_{0};


        LayersFrame *layers_frame_;
};

} // namespace s21


