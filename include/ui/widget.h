#pragma once

#include <QFile>
#include <QFontDatabase>
#include <QListWidgetItem>
#include <QWidget>
#include <core/client.h>
#include <ui/login.h>

namespace Ui
{
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

  public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

    void initUI();      //初始化界面
    void initConnect(); //初始化信号槽
    void loginPage();   //打开登录对话框
    Client *client;

  private slots:
    void addServerItem(Server *server);

  private:
    QList<QListWidgetItem *> serverItemList;
    QList<QListWidgetItem *> sessionItemList;
    QList<QListWidgetItem *> messageItemList;
    Ui::Widget *ui;
};