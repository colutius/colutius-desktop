#include "ui_login.h"
#include <ui/login.h>

Login::Login(QWidget *parent) : QDialog(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    this->initUI();
    //设置模态对话框
    this->setModal(true);
    this->show();
}

Login::~Login()
{
    delete ui;
}
void Login::initUI()
{
    //设置qss样式
    QFile qssFile(":/qss/qss/Login.qss");
    qssFile.open(QFile::ReadOnly);
    QString str = qssFile.readAll();
    this->setStyleSheet(str);
}
