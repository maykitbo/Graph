#pragma once

#include "abs_image.h"

#include <QPainterPath>

namespace s21 {

class Graph : public AbsImage
{
    public:
        using data_t = std::vector<std::pair<double, double>>;
    
        Graph(GraphParams &params,
            const QString &name,
            const QPen &graph_pen = QPen(Qt::black, 2),
            QImage::Format format = QImage::Format_ARGB32);

        Graph(GraphParams &params,
            const QString &name,
            const data_t &data,
            const QPen &graph_pen = QPen(Qt::black, 2),
            QImage::Format format = QImage::Format_ARGB32);

        Graph(GraphParams &params,
            const QString &name,
            data_t &&data,
            const QPen &graph_pen = QPen(Qt::black, 2),
            QImage::Format format = QImage::Format_ARGB32);
        
        Graph(const Graph &other) = default;
        Graph(Graph &&other) = default;
        
        void Draw() override;
        
        void DrawingPoints(bool draw_points);
        void DrawingLines(bool draw_lines);
        void SetPointsPen(QPen pen);
        void SetGraphPen(QPen pen);
        void SetMaxPointOnOneGraph(unsigned max_point_on_one_graph);
        // void SetNameFormat(const std::function<QString(QString, unsigned)> &name_format);
        
        const QPen &GetGraphPen() const noexcept;
        const QPen &GetPointsPen() const noexcept;

        qreal MinX() const noexcept;
        qreal MaxX() const noexcept;
        qreal MinY() const noexcept;
        qreal MaxY() const noexcept;

    private:
        std::vector<std::pair<double, double>> data_;
        bool draw_points_{false};
        bool draw_lines_{true};
        QPen points_pen_;
        QPen graph_pen_;
        unsigned max_point_on_one_graph_{30000};

        qreal min_x_;
        qreal max_x_;
        qreal min_y_;
        qreal max_y_;

        void MinMax();

        static QColor ColorInvert(const QColor &color);
        static QString NameFormat(const QString &name, unsigned size);
};


} // namespace s21
