#include "ui_widget.h"
#include <core/notifymanager.h>
#include <ui/widget.h>
Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->initUI();
}
Widget::~Widget()
{
    delete ui;
}
void Widget::initUI()
{
    //加载字体图标库
    int fontId = QFontDatabase::addApplicationFont(":/font/iconfont/iconfont.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    const auto &fontName = fontFamilies.at(0);
    QFont iconfont;
    iconfont.setFamily(fontName);
    iconfont.setPointSize(40);
    //设置图标
    ui->sendBtn->setFont(iconfont);
    ui->sendBtn->setText(QChar(0xe60c));
    ui->addServerBtn->setFont(iconfont);
    ui->addServerBtn->setText(QChar(0xe696));
    ui->settingBtn->setFont(iconfont);
    ui->settingBtn->setText(QChar(0xe8b8));
    //设置qss样式
    QFile qssFile(":/qss/qss/Widget.qss");
    qssFile.open(QFile::ReadOnly);
    QString str = qssFile.readAll();
    this->setStyleSheet(str);
}