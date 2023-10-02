#pragma once

#include <QImage>
#include <QPainter>
#include <QPen>

#include "parameters.h"

namespace s21 {

class AbsImage : public QObject
{
    Q_OBJECT

    public:
        AbsImage(GraphParams &params,
                    const QString &name,
                    QSize size,
                    QImage::Format format = QImage::Format_ARGB32);

        virtual void Draw() = 0;
        void Resize(QSize size);
        void SetName(const QString &name);

        QSize GetSize() const noexcept;
        const QString &GetName() const noexcept;
        const QImage &GetImage() const noexcept;

        void SavePng(const QString &path) const;

        virtual ~AbsImage() = default;

        AbsImage(const AbsImage &other);
        AbsImage(AbsImage &&other);
    
    signals:
        void Remove();
        void ReDraw();

    protected:
        GraphParams &p_;
        QImage image_;
        QPainter painter_;

        QString name_;   
};


} // namespace s21
