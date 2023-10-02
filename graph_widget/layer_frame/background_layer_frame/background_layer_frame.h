#ifndef BACKGROUND_LAYER_FRAME_H
#define BACKGROUND_LAYER_FRAME_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class background_layer_frame; }
QT_END_NAMESPACE

class background_layer_frame : public QWidget
{
    Q_OBJECT

public:
    background_layer_frame(QWidget *parent = nullptr);
    ~background_layer_frame();

private:
    Ui::background_layer_frame *ui;
};
#endif // BACKGROUND_LAYER_FRAME_H
