#include "ui_widget.h"
#include <core/notifymanager.h>
#include <ui/widget.h>
QChar getFontID(QChar letter);
Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    this->client = new Client;
    ui->setupUi(this);
    this->initUI();
    this->initConnect();
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
void Widget::initConnect()
{
    connect(ui->addServerBtn, &QPushButton::clicked, this, &Widget::loginPage);
    connect(client, &Client::loginSuccess, this, &Widget::addServerItem);
}
//打开登录页面
void Widget::loginPage()
{
    auto *loginpage = new Login(this->client);
    loginpage->show();
}
//添加服务器图标
void Widget::addServerItem(Server *server)
{
    auto *serverItem = new QListWidgetItem;
    serverItem->setToolTip("地址:" + server->getHost() + "\n" + "昵称:" + server->getNick());
    //初始化字母字体
    int fontId = QFontDatabase::addApplicationFont(":/font/iconfont/letter.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    const auto &fontName = fontFamilies.at(0);
    QFont letterFont;
    letterFont.setFamily(fontName);
    letterFont.setPointSize(40);
    serverItem->setFont(letterFont);
    //设置server图标
    QStringList name = server->getHost().split(".");
    serverItem->setText(getFontID(name.at(1)[0]));
    this->serverItemList.append(serverItem);
    ui->serverList->addItem(serverItem);
    ui->serverList->setCurrentItem(serverItem);
}
//获取字母对应图标ID
QChar getFontID(QChar letter)
{
    switch (letter.unicode())
    {
    case u'a':
        return QChar(0xeb87);
    case u'b':
        return QChar(0xeb88);
    case u'c':
        return QChar(0xeb85);
    case u'd':
        return QChar(0xeb86);
    case u'e':
        return QChar(0xeb8a);
    case u'f':
        return QChar(0xeb89);
    case u'g':
        return QChar(0xeb8b);
    case u'h':
        return QChar(0xeb8d);
    case u'i':
        return QChar(0xeb8c);
    case u'j':
        return QChar(0xeb8e);
    case u'k':
        return QChar(0xeb97);
    case u'l':
        return QChar(0xeb8f);
    case u'm':
        return QChar(0xeb93);
    case u'n':
        return QChar(0xeb91);
    case u'o':
        return QChar(0xeb90);
    case u'p':
        return QChar(0xeb92);
    case u'q':
        return QChar(0xeb95);
    case u'r':
        return QChar(0xeb96);
    case u's':
        return QChar(0xeb9f);
    case u't':
        return QChar(0xeb98);
    case u'u':
        return QChar(0xeb9b);
    case u'v':
        return QChar(0xeb99);
    case u'w':
        return QChar(0xeb9a);
    case u'x':
        return QChar(0xeb9e);
    case u'y':
        return QChar(0xeb9d);
    case u'z':
        return QChar(0xeb9c);
    default:
        return QChar(0xeb94);
    }
}