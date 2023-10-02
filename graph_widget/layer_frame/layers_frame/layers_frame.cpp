#include "layers_frame.h"
#include "./ui_layers_frame.h"

layers_frame::layers_frame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::layers_frame)
{
    ui->setupUi(this);
}

layers_frame::~layers_frame()
{
    delete ui;
}

