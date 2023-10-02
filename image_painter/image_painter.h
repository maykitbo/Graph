#pragma once

#include "painters/background.h"
#include "painters/graph.h"

#include <vector>
#include <iostream>

#include <QGuiApplication>

#include <cstdlib> // For std::system


namespace s21 {

class ImagePainter
{
    public:
        ImagePainter(const QSize &size, int argc, char *argv[]);

        Graph &AddGraph(const Graph::data_t &data,
                        const QString &name,
                        const QPen &graph_pen);

        Graph &AddGraph(Graph::data_t &&data,
                        const QString &name,
                        const QPen &graph_pen);
        
        void AddGraph(const Graph &graph);
        void AddGraph(Graph &&graph);

        void ReserveGraphs(unsigned size);
        
        Graph &AddGraph(const Graph::data_t &data, const QString &name);
        Graph &AddGraph(Graph::data_t &&data, const QString &name);

        void SavePng(const QString &path);
        
        Background &GetBackground();
        Graph &operator[](unsigned index);
    
    private:
        QGuiApplication app_;
        GraphParams p_;

        Background background_;
        std::vector<Graph> graphs_;

        void OpenPng(const QString &path);

        std::vector<QColor> colors_{
            QColor(255, 0, 0), // red
            QColor(0, 255, 0), // green
            QColor(0, 0, 255), // blue
            QColor(255, 255, 0), // yellow
            QColor(255, 0, 255), // magenta
            QColor(0, 255, 255), // cyan
            QColor(255, 128, 0), // orange
            QColor(128, 0, 255), // purple
            QColor(255, 0, 128), // pink
            QColor(128, 64, 0), // brown
            QColor(128, 128, 0), // olive
            QColor(0, 128, 128), // teal
            QColor(0, 64, 128), // navy
            QColor(128, 128, 128), // gray
            QColor(128, 0, 0), // dark red
            QColor(0, 128, 0), // dark green
            QColor(0, 0, 128), // dark blue
            QColor(128, 128, 0), // dark yellow
            QColor(128, 0, 128), // dark magenta
            QColor(0, 128, 128), // dark cyan
            QColor(128, 64, 0), // dark orange
            QColor(64, 0, 128), // dark purple
            QColor(128, 0, 64), // dark pink
            QColor(64, 32, 0), // dark brown
            QColor(64, 64, 0), // dark olive
            QColor(0, 64, 64), // dark teal
            QColor(0, 32, 64), // dark navy
            QColor(64, 64, 64), // dark gray
        };
        
        
};
















} // namespace s21
