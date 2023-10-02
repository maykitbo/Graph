#include "image_painter.h"

using namespace s21;


ImagePainter::ImagePainter(const QSize &size, int argc, char *argv[])
    : app_(argc, argv)
    , p_(size)
    , background_(p_)
{
    p_.SetTopIndent(40);
}

Graph &ImagePainter::AddGraph(const Graph::data_t &data,
                const QString &name,
                const QPen &graph_pen)
{
    graphs_.emplace_back(p_, name, data, graph_pen);
    return graphs_.back();
}

Graph &ImagePainter::AddGraph(Graph::data_t &&data,
                const QString &name,
                const QPen &graph_pen)
{
    graphs_.emplace_back(p_, name, data, graph_pen);
    return graphs_.back();
}

Graph &ImagePainter::AddGraph(const Graph::data_t &data, const QString &name)
{
    if (graphs_.size() >= colors_.size())
    {
        std::cerr << "Warning: more graphs than colors, graph will be red\n";
        graphs_.emplace_back(p_, name, data, QPen(Qt::red));
    }
    graphs_.emplace_back(p_, name, data, QPen(colors_[graphs_.size()]));
    return graphs_.back();
}

Graph &ImagePainter::AddGraph(Graph::data_t &&data, const QString &name)
{
    if (graphs_.size() >= colors_.size())
    {
        std::cerr << "Warning: more graphs than colors, graph will be red\n";
        graphs_.emplace_back(p_, name, data, QPen(Qt::red));
    }
    graphs_.emplace_back(p_, name, std::move(data), QPen(colors_[graphs_.size()]));
    return graphs_.back();
}

void ImagePainter::ReserveGraphs(unsigned size)
{
    graphs_.reserve(size);
}

void ImagePainter::AddGraph(const Graph &graph)
{
    graphs_.push_back(graph);
}

void ImagePainter::AddGraph(Graph &&graph)
{
    graphs_.push_back(graph);
}

void ImagePainter::SavePng(const QString &path)
{
    if (graphs_.empty())
    {
        std::cerr << "Warning: no graphs to save\n";
        return;
    }
    background_.SetShowText(true);
    p_.SetFactors();
    QImage image(p_.Size(), QImage::Format_ARGB32);
    QPainter painter(&image);
    background_.Draw();
    painter.drawImage(0, 0, background_.GetImage());

    unsigned names_step = p_.Size().width() / graphs_.size();
    unsigned name_i = names_step / 2;
    for (auto &graph : graphs_)
    {
        graph.Draw();
        painter.drawImage(p_.Left(), p_.Top(), graph.GetImage());

        painter.setPen(graph.GetGraphPen());
        painter.setFont(background_.GetTextFont());
        painter.drawText(name_i, p_.Top() - 10, graph.GetName());
        name_i += names_step;
    }
    painter.end();
    
    QString p = path.endsWith(".png") ? path : path + ".png";
    image.save(p);

    OpenPng(p);
}

void ImagePainter::OpenPng(const QString &path)
{
#ifdef _WIN32
    // Code to open the image on Windows
    std::system(("start " + path.toStdString()).c_str());
#elif __APPLE__
    // Code to open the image on macOS
    std::system(("open " + path.toStdString()).c_str());
#else
    // Code to open the image on Linux/Unix
    std::system(("xdg-open " + path.toStdString()).c_str());
#endif
}

Background &ImagePainter::GetBackground()
    { return background_; }

Graph &ImagePainter::operator[](unsigned index)
{
    if (index >= graphs_.size())
        throw std::out_of_range("Graph index out of range");
    return graphs_[index];
}

