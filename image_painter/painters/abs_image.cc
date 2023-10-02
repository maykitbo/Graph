#include "abs_image.h"



using namespace s21;

AbsImage::AbsImage(GraphParams &params,
                    const QString &name,
                    QSize size,
                    QImage::Format format)
    : image_(size, format)
    , p_(params)
    , name_(name)
    {}

AbsImage::AbsImage(const AbsImage &other)
    : p_(other.p_)
    , image_(other.image_)
    , name_(other.name_)
    {}

AbsImage::AbsImage(AbsImage &&other)
    : p_(other.p_)
    , image_(std::move(other.image_))
    , name_(std::move(other.name_))
    {}


void AbsImage::Resize(QSize size)
{
    image_ = QImage(size, image_.format());
    Draw();
}

void AbsImage::SetName(const QString &name)
    { name_ = name; }

QSize AbsImage::GetSize() const noexcept
    { return image_.size(); }

const QString &AbsImage::GetName() const noexcept
    { return name_; }

const QImage &AbsImage::GetImage() const noexcept
    { return image_; }

void AbsImage::SavePng(const QString &path) const
{
    image_.save(path.endsWith(".png") ? path : path + ".png");
    // if (path.endsWith(".png"))
    //     image_.save(path);
    // else
    //     image_.save(path + ".png");
}
