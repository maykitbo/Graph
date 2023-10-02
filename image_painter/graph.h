#pragma once

#include "virtual.h"

#include <QPainterPath>

namespace s21 {

class Graph final : public ImagePainter
{
    public:
        Graph(GraphParams &params,
            GraphStyle &style,
            const QString &name,
            const QPen &graph_pen_ = QPen(),
            const QPen &points_pen = QPen(),
            QImage::Format format = QImage::Format_ARGB32);

        Graph(GraphParams &params,
            GraphStyle &style,
            const QString &name,
            const std::vector<std::pair<double, double>> &data,
            const QPen &graph_pen_ = QPen(),
            const QPen &points_pen = QPen(),
            QImage::Format format = QImage::Format_ARGB32);

        Graph(GraphParams &params,
            GraphStyle &style,
            const QString &name,
            std::vector<std::pair<double, double>> &&data,
            const QPen &graph_pen_ = QPen(),
            const QPen &points_pen = QPen(),
            QImage::Format format = QImage::Format_ARGB32);

        void Draw() override;
        
        void DrawingPoints(bool draw_points);
        void DrawingLines(bool draw_lines);
        void SetPointsPen(QPen color);
        void SetGraphPen(QPen color);
        
        const QPen &GetGraphPen() const noexcept;
        const QPen &GetPointsPen() const noexcept;

        qreal MinX() const noexcept
            { return min_x_; }
        qreal MaxX() const noexcept
            { return max_x_; }
        qreal MinY() const noexcept
            { return min_y_; }
        qreal MaxY() const noexcept
            { return max_y_; }

    private:
        std::vector<std::pair<double, double>> data_;
        bool draw_points_{false};
        bool draw_lines_{true};
        QPen points_pen_;
        QPen graph_pen_;

        qreal min_x_;
        qreal max_x_;
        qreal min_y_;
        qreal max_y_;

        void MinMax();
};


} // namespace s21
