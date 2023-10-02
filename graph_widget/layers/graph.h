#pragma once

#include "virtual.h"

#include <QPainterPath>

namespace s21 {

class GraphLayer : public VirtualLayer
{
    Q_OBJECT
    public:
        GraphLayer(GraphParams &params,
                    GraphStyle &style,
                    const QString &name,
                    const QPen &graph_pen_,
                    const std::vector<std::pair<double, double>> &data,
                    const QPen &points_pen = QPen(Qt::red),
                    QImage::Format format = QImage::Format_ARGB32);

        GraphLayer(GraphParams &params,
                    GraphStyle &style,
                    const QString &name,
                    const QPen &graph_pen_,
                    std::vector<std::pair<double, double>> &&data,
                    const QPen &points_pen = QPen(Qt::red),
                    QImage::Format format = QImage::Format_ARGB32);

        void Drawing() override;
        

        void DrawingPoints(bool draw_points);
        void DrawingLines(bool draw_lines);
        void SetPointsColor(QColor color);
        void SetGraphColor(QColor color);
        void SetRemovable(bool removable);
        
        bool Visible() const noexcept;
        void SetDrawPoints(bool draw_points);
        QColor GetGraphColor() const noexcept;
        void SetBackgroundColor(QColor color);

        qreal MinX() const noexcept
            { return min_x_; }
        qreal MaxX() const noexcept
            { return max_x_; }
        qreal MinY() const noexcept
            { return min_y_; }
        qreal MaxY() const noexcept
            { return max_y_; }
        
        virtual ~GraphLayer();
    
    signals:
        void ChangeVisible(bool visible);

    private:
        std::vector<std::pair<double, double>> data_;
        bool draw_points_{false};
        bool draw_lines_{true};
        QPen points_pen_;
        QPen graph_pen_;
        QColor backgrpund_color_ = Qt::transparent;

        QPushButton *remove_button_{nullptr};
        QRadioButton *visible_button_{nullptr};

        qreal min_x_;
        qreal max_x_;
        qreal min_y_;
        qreal max_y_;

        bool visible_{true};

        void InitFrames();
        void MinMax();
};


} // namespace s21
