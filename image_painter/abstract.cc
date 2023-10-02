#include "abstract.h"

using namespace s21;

ImagePainter::ImagePainter(GraphParams &params,
                    GraphStyle &style,
                    const QString &name,
                    QSize size,
                    QImage::Format format)
    : image_(size, format)
    , p_(params)
    , s_(style)
    , name_(name)
    {}

void ImagePainter::Resize(QSize size)
{
    image_ = QImage(size, image_.format());
    Draw();
}

void ImagePainter::SetName(const QString &name)
    { name_ = name; }

const QSize &ImagePainter::GetSize() const noexcept
    { return image_.size(); }

const QString &ImagePainter::GetName() const noexcept
    { return name_; }

const QImage &ImagePainter::GetImage() const noexcept
    { return image_; }


