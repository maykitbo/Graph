#pragma once

#include "abstract.h"

namespace s21 {

enum GridTextType
{
    Number,
    DateSec,
    DateDay
};

class Background final : public ImagePainter
{
    public:
        Background(GraphParams &params,
                        GraphStyle &style,
                        QImage::Format format = QImage::Format_RGB16);

        void Draw() override;

        void SetAxes(bool axes) noexcept;
        void SetHorizontalGrid(bool grid) noexcept;
        void SetVerticalGrid(bool grid) noexcept;
        void SetGrid(bool grid) noexcept;
        void SetShowText(bool show) noexcept;
        void SetXTextType(GridTextType type) noexcept;
        void SetYTextType(GridTextType type) noexcept;
    
    private:
        bool axes_{true};
        bool horizontal_grid_{true};
        bool vertical_grid_{true};
        bool show_text_{false};

        using TextFunc = QString (Background::*)(double) const noexcept;

        QString NumberFormat(double n) const noexcept
            { return QString::number(n, s_.number_format.first,
                                    s_.number_format.second); }

        QString DateFormatSec(double n) const noexcept
            { return QDateTime::fromSecsSinceEpoch(n).toString(s_.date_format); }
        
        QString DateFormatDay(double n) const noexcept
            { return QDateTime::fromSecsSinceEpoch(n * 60 * 60 * 24).toString(s_.date_format); }


        TextFunc TextFuncSwitch(GridTextType type) const noexcept;

        TextFunc x_text_func_{&Background::DateFormatDay};
        TextFunc y_text_func_{&Background::NumberFormat};
};

} // namespace s21

