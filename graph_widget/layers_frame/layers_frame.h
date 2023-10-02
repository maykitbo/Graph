#pragma once

#include "layers/background.h"
#include "layers/graph.h"
#include "common/style.h"

#include <QScrollArea>
#include <QMouseEvent>


namespace s21 {


class LayersFrame : public QScrollArea
{
    Q_OBJECT

    public:
        LayersFrame(GraphParams &params, GraphStyle &style, QWidget *parent = nullptr);

        void AddGraph(const QString &name,
                std::vector<std::pair<double, double>> &data, bool points);

        void Clear();
        void Resize();

        // void ForVisible(const std::function<void(qreal, qreal, QImage*)> &func);
        BackgroundLayer *GetBackground() { return background_; }
        void Draw();
        void ForVisible(const std::function<void(GraphLayer*)> &func);
        void ForGraphLayers(const std::function<void(GraphLayer*)> &func);

        ~LayersFrame();

    signals:
        void GraphRemoved();
        void ReDraw();
    
    protected:
        bool eventFilter(QObject *object, QEvent *event) override;
    
    private:
        QWidget *widget_;
        // QScrollArea *scroll_area_;

        BackgroundLayer *background_;
        QVBoxLayout *layout_;
        QPoint drag_start_pos_;
        VirtualLayer *dragged_layer_{nullptr};

        GraphStyle &s_;
        GraphParams &p_;

        int visible_count_{0};

        bool LablePressed(QLabel *label, QEvent *event);
        bool LableReleased(QLabel *label, QEvent *event);
        bool LableMove(QLabel *label, QEvent *event);


        void ProcessMinMax();
};






} // namespace s21
