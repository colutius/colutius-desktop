//
// Created by hgy on 2022/5/10.
//

// You may need to build the project (run Qt uic code generator) to get
// "ui_Widget.h" resolved

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }
