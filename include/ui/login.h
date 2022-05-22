#pragma once

#include <QDialog>
#include <QFile>
#include <core/client.h>

namespace Ui
{
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

  public:
    explicit Login(Client *client, QWidget *parent = nullptr);
    ~Login() override;

    void initUI(); //初始化界面
    void login();

    Client *client;

  private:
    Ui::Login *ui;
};