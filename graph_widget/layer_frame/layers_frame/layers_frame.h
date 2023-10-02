#ifndef LAYERS_FRAME_H
#define LAYERS_FRAME_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class layers_frame; }
QT_END_NAMESPACE

class layers_frame : public QWidget
{
    Q_OBJECT

public:
    layers_frame(QWidget *parent = nullptr);
    ~layers_frame();

private:
    Ui::layers_frame *ui;
};
#endif // LAYERS_FRAME_H
