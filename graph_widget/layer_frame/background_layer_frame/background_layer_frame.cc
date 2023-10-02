#include "background_layer_frame.h"
#include "./ui_background_layer_frame.h"

background_layer_frame::background_layer_frame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::background_layer_frame)
{
    ui->setupUi(this);
}

background_layer_frame::~background_layer_frame()
{
    delete ui;
}

