#pragma once

#include <QImage>
#include <QPainter>
#include <QPen>

#include <QFrame>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QBoxLayout>

#include "common/parameters.h"
#include "common/style.h"

namespace s21 {

class VirtualLayer : public QFrame
{
    Q_OBJECT

    public:
        VirtualLayer(GraphParams &params,
                    GraphStyle &style,
                    const QString &name,
                    QSize size,
                    QImage::Format format = QImage::Format_ARGB32);

        virtual void Drawing() = 0;
        virtual void Resize(QSize size);

        QImage *GetImage() noexcept;

        QLabel *NameLabel() const noexcept;
        virtual ~VirtualLayer();
    
    signals:
        void Remove();
        void ReDraw();

    protected:
        GraphStyle &s_;
        GraphParams &p_;
        QImage image_;
        QPainter painter_;

        QString name_;
        // QFrame *frame_;
        QLabel *name_label_;
        QPushButton *hide_button_{nullptr};
        QHBoxLayout *h_layout_;
        QVBoxLayout *v_layout_;
        QFrame *settings_{nullptr};
        // bool visible_{true};

        void CreateSettingsFrame();

        
    
    private:
        void InitFrame();
};


} // namespace s21


