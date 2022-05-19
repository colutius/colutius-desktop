#include <ui/config.h>
#include "ui_config.h"

Config::Config(QWidget *parent) : QDialog(parent), ui(new Ui::Config)
{
    ui->setupUi(this);
    //设置模态对话框
    this->setModal(true);
    this->show();
}
Config::~Config()
{
    delete ui;
}