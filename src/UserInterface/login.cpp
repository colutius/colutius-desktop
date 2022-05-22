#include "ui_login.h"
#include <ui/login.h>

Login::Login(Client *client, QWidget *parent) : QDialog(parent), ui(new Ui::Login)
{
    this->client = client;
    ui->setupUi(this);
    this->initUI();
    //设置模态对话框
    this->setModal(true);
    this->show();
    connect(ui->connectBtn, &QPushButton::clicked, this, &Login::login);
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
void Login::login()
{
    QString host = ui->hostEdit->text();
    QString port = ui->portEdit->text();
    QString nick = ui->nickEdit->text();
    QString user = ui->userEdit->text();
    QString passwd = ui->passwdEdit->text();
    if (host.isEmpty() || port.isEmpty())
    {
        qWarning("host和port不能为空");
        return;
    }
    if (nick.isEmpty() || user.isEmpty())
    {
        qWarning("nick和user不能为空");
        return;
    }
    client->addServer(host, port.toInt(), nick, user, passwd);
    connect(client, &Client::loginSuccess, this, &Login::close);
}
