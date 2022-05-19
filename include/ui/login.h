#pragma once

#include <QDialog>
#include <QFile>

namespace Ui
{
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

  public:
    explicit Login(QWidget *parent = nullptr);
    ~Login() override;

    void initUI(); //初始化界面

  private:
    Ui::Login *ui;
};