/********************************************************************************
** Form generated from reading UI file 'grpah_layer_frame.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRPAH_LAYER_FRAME_H
#define UI_GRPAH_LAYER_FRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QRadioButton *visible_radio;
    QLabel *name_lable;
    QPushButton *hide_button;
    QPushButton *remove_button;
    QFrame *settings_frame;
    QVBoxLayout *verticalLayout_3;
    QFrame *line_frame;
    QVBoxLayout *verticalLayout;
    QRadioButton *line_radio;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *line_width_spin;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QToolButton *line_color_tool;
    QFrame *points_frame;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *points_radio;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpinBox *points_size_spin;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QToolButton *points_color_tool;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(196, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(Widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        visible_radio = new QRadioButton(Widget);
        visible_radio->setObjectName(QString::fromUtf8("visible_radio"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(visible_radio->sizePolicy().hasHeightForWidth());
        visible_radio->setSizePolicy(sizePolicy1);
        visible_radio->setMinimumSize(QSize(20, 20));
        visible_radio->setMaximumSize(QSize(20, 20));
        visible_radio->setChecked(true);
        visible_radio->setAutoExclusive(false);

        horizontalLayout->addWidget(visible_radio);

        name_lable = new QLabel(Widget);
        name_lable->setObjectName(QString::fromUtf8("name_lable"));
        name_lable->setEnabled(true);
        sizePolicy1.setHeightForWidth(name_lable->sizePolicy().hasHeightForWidth());
        name_lable->setSizePolicy(sizePolicy1);
        name_lable->setMinimumSize(QSize(128, 20));
        name_lable->setMaximumSize(QSize(128, 20));

        horizontalLayout->addWidget(name_lable);

        hide_button = new QPushButton(Widget);
        hide_button->setObjectName(QString::fromUtf8("hide_button"));
        sizePolicy1.setHeightForWidth(hide_button->sizePolicy().hasHeightForWidth());
        hide_button->setSizePolicy(sizePolicy1);
        hide_button->setMinimumSize(QSize(20, 20));
        hide_button->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(hide_button);

        remove_button = new QPushButton(Widget);
        remove_button->setObjectName(QString::fromUtf8("remove_button"));
        sizePolicy1.setHeightForWidth(remove_button->sizePolicy().hasHeightForWidth());
        remove_button->setSizePolicy(sizePolicy1);
        remove_button->setMinimumSize(QSize(20, 20));
        remove_button->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(remove_button);


        verticalLayout_4->addLayout(horizontalLayout);

        settings_frame = new QFrame(Widget);
        settings_frame->setObjectName(QString::fromUtf8("settings_frame"));
        settings_frame->setFrameShape(QFrame::StyledPanel);
        settings_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(settings_frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        line_frame = new QFrame(settings_frame);
        line_frame->setObjectName(QString::fromUtf8("line_frame"));
        line_frame->setFrameShape(QFrame::StyledPanel);
        line_frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(line_frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line_radio = new QRadioButton(line_frame);
        line_radio->setObjectName(QString::fromUtf8("line_radio"));
        line_radio->setChecked(true);
        line_radio->setAutoExclusive(false);

        verticalLayout->addWidget(line_radio);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(line_frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        line_width_spin = new QSpinBox(line_frame);
        line_width_spin->setObjectName(QString::fromUtf8("line_width_spin"));
        line_width_spin->setMinimum(1);
        line_width_spin->setMaximum(10);
        line_width_spin->setValue(2);

        horizontalLayout_2->addWidget(line_width_spin);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(line_frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        line_color_tool = new QToolButton(line_frame);
        line_color_tool->setObjectName(QString::fromUtf8("line_color_tool"));
        line_color_tool->setMinimumSize(QSize(64, 0));

        horizontalLayout_3->addWidget(line_color_tool);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(line_frame);

        points_frame = new QFrame(settings_frame);
        points_frame->setObjectName(QString::fromUtf8("points_frame"));
        points_frame->setFrameShape(QFrame::StyledPanel);
        points_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(points_frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        points_radio = new QRadioButton(points_frame);
        points_radio->setObjectName(QString::fromUtf8("points_radio"));
        points_radio->setAutoExclusive(false);

        verticalLayout_2->addWidget(points_radio);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(points_frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        points_size_spin = new QSpinBox(points_frame);
        points_size_spin->setObjectName(QString::fromUtf8("points_size_spin"));
        points_size_spin->setMinimum(1);
        points_size_spin->setMaximum(20);
        points_size_spin->setValue(3);

        horizontalLayout_4->addWidget(points_size_spin);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(points_frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        points_color_tool = new QToolButton(points_frame);
        points_color_tool->setObjectName(QString::fromUtf8("points_color_tool"));
        points_color_tool->setMinimumSize(QSize(64, 0));

        horizontalLayout_5->addWidget(points_color_tool);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_3->addWidget(points_frame);


        verticalLayout_4->addWidget(settings_frame);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        visible_radio->setText(QString());
        name_lable->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        hide_button->setText(QCoreApplication::translate("Widget", "+", nullptr));
        remove_button->setText(QCoreApplication::translate("Widget", "x", nullptr));
        line_radio->setText(QCoreApplication::translate("Widget", "Line", nullptr));
        label->setText(QCoreApplication::translate("Widget", "width", nullptr));
        line_width_spin->setSuffix(QString());
        line_width_spin->setPrefix(QString());
        label_2->setText(QCoreApplication::translate("Widget", "color", nullptr));
        line_color_tool->setText(QCoreApplication::translate("Widget", "...", nullptr));
        points_radio->setText(QCoreApplication::translate("Widget", "Points", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "size", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "color", nullptr));
        points_color_tool->setText(QCoreApplication::translate("Widget", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRPAH_LAYER_FRAME_H
