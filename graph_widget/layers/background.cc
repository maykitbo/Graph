#include "background.h"

using namespace s21;

BackgroundLayer::BackgroundLayer(GraphParams &params,
                GraphStyle &style,
                const QString &name,
                QImage::Format format)
    : VirtualLayer(params, style, name, params.Size(), format)
{
    InitFrames();
}

void BackgroundLayer::InitFrames()
{
    h_layout_->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    // h_layout_->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    h_layout_->insertSpacerItem(0, new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));

    CreateSettingsFrame();

}


BackgroundLayer::TextFunc BackgroundLayer::TextFuncSwitch(GridTextType type) const noexcept
{
    switch (type)
    {
    case Number:
        return &BackgroundLayer::NumberFormat;
    case DateSec:
        return &BackgroundLayer::DateFormatSec;
    case DateDay:
        return &BackgroundLayer::DateFormatDay;
    }
    return &BackgroundLayer::NumberFormat;
}


void BackgroundLayer::Drawing()
{
    painter_.begin(&image_);
    image_.fill(s_.background_color);
    if (axes_ == true)
    {
        painter_.setPen(s_.axes_pen);
        // draw vertical axes
        painter_.drawLine(p_.Left(), p_.Top(),
                          p_.Left(), p_.Bottom());
        // draw horizontal axes
        painter_.drawLine(p_.Left(), p_.Bottom(),
                          p_.Right(), p_.Bottom());
    }

    unsigned min, max;
    painter_.setPen(s_.grid_pen);
    if (vertical_grid_)
    {
        min = p_.Left();
        max = p_.Right();
        for (unsigned i = min; i < max; i += s_.x_grid_step)
        {
            painter_.drawLine(i, p_.Top(), i, p_.Bottom());
        }
    }
    if (horizontal_grid_)
    {
        min = p_.Top();
        max = p_.Bottom();
        for (unsigned i = min; i < max; i += s_.y_grid_step)
        {
            painter_.drawLine(p_.Left(), i, p_.Right(), i);
        }
    }
    painter_.setPen(s_.axes_pen);
    painter_.setFont(s_.text_font);
    if (show_text_ && vertical_grid_)
    {
        min = p_.Top();
        max = p_.Bottom();
        for (unsigned i = min; i < max; i += s_.y_grid_step)
        {
            painter_.drawText(s_.left_text_indent, i,
                            (*this.*y_text_func_)(p_.YToDataCords(i)));
        }
    }
    if (show_text_ && horizontal_grid_)
    {
        min = p_.Left();
        max = p_.Right();
        for (unsigned i = min; i < max; i += s_.x_grid_step)
        {
            // TODO Why 30?
            painter_.drawText(i - 30, p_.Bottom() + s_.bottom_text_indent,
                            (*this.*x_text_func_)(p_.XToDataCords(i)));
        }
    }
    painter_.end();
    
}




void BackgroundLayer::SetAxes(bool axes) noexcept
    { axes_ = axes; }

void BackgroundLayer::SetHorizontalGrid(bool grid) noexcept
    { horizontal_grid_ = grid; }

void BackgroundLayer::SetVerticalGrid(bool grid) noexcept
    { vertical_grid_ = grid; }

void BackgroundLayer::SetGrid(bool grid) noexcept
{
    horizontal_grid_ = grid;
    vertical_grid_ = grid;
}

void BackgroundLayer::SetShowText(bool show) noexcept
    { show_text_ = show; }

void BackgroundLayer::SetXTextType(GridTextType type) noexcept
    { x_text_func_ = TextFuncSwitch(type); }

void BackgroundLayer::SetYTextType(GridTextType type) noexcept
    { y_text_func_ = TextFuncSwitch(type); }
