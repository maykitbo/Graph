#pragma once

#include <QImage>
#include <QPainter>
#include <QPen>

#include "common/parameters.h"
#include "common/style.h"

namespace s21 {

class ImagePainter
{
    Q_OBJECT

    public:
        ImagePainter(GraphParams &params,
                    GraphStyle &style,
                    const QString &name,
                    QSize size,
                    QImage::Format format = QImage::Format_ARGB32);

        virtual void Draw() = 0;
        void Resize(QSize size);
        void SetName(const QString &name);

        const QSize &GetSize() const noexcept;
        const QString &GetName() const noexcept;
        const QImage &GetImage() const noexcept;

        virtual ~ImagePainter() = default;
    
    signals:
        void Remove();
        void ReDraw();

    protected:
        GraphStyle &s_;
        GraphParams &p_;
        QImage image_;
        QPainter painter_;

        QString name_;   
};


} // namespace s21
