#include "virtual.h"

using namespace s21;


VirtualLayer::VirtualLayer(GraphParams &params,
                    GraphStyle &style,
                    const QString &name,
                    QSize size,
                    QImage::Format format)
    : image_(size, format)
    , p_(params)
    , s_(style)
    , name_(name)
    , QFrame(nullptr)
{
    InitFrame();
}

void VirtualLayer::InitFrame()
{
    v_layout_ = new QVBoxLayout(this);
    h_layout_ = new QHBoxLayout();
    h_layout_->setSpacing(2);
    v_layout_->setContentsMargins(2, 2, 2, 2);
    v_layout_->addLayout(h_layout_);
    v_layout_->setSpacing(0);
    name_label_ = new QLabel(name_, this);
    name_label_->setAlignment(Qt::AlignLeft);
    // name_label_->setMaximumSize(250, 20);
    name_label_->setFixedSize(128, 20);
    name_label_->setFont(s_.text_font);
    
    h_layout_->addWidget(name_label_);

    setFixedWidth(196);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    setLayout(v_layout_);
}

void VirtualLayer::CreateSettingsFrame()
{
    hide_button_ = new QPushButton("+", this);
    hide_button_->setFixedSize(20, 20);
    settings_ = new QFrame(this);
    settings_->setVisible(false);
    // settings_->setFrameStyle(QFrame::Box);
    h_layout_->addWidget(hide_button_);
    v_layout_->addWidget(settings_);
    connect(hide_button_, &QPushButton::clicked, this, [&] ()
    {
        if (settings_->isVisible())
        {
            settings_->setVisible(false);
            hide_button_->setText("+");
        }
        else
        {
            settings_->setVisible(true);
            hide_button_->setText("-");
        }
    });
}



void VirtualLayer::Resize(QSize size)
{
    image_ = QImage(size, image_.format());
    Drawing();
}

QImage *VirtualLayer::GetImage() noexcept
{ 
    return &image_;
}

QLabel *VirtualLayer::NameLabel() const noexcept
{
    return name_label_;
}

VirtualLayer::~VirtualLayer()
{
    delete h_layout_;
    delete v_layout_;
    delete name_label_;
    // if (remove_button_ != nullptr)
    //     delete remove_button_;
    // if (visible_button_ != nullptr)
    //     delete visible_button_;
    if (hide_button_ != nullptr)
        delete hide_button_;
    if (settings_ != nullptr)
        delete settings_;
}

