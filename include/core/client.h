#pragma once
#include <QObject>
#include <libcolutius/Server.h>

class Client : public QObject
{
    Q_OBJECT
  signals:
    void loginSuccess(Server *server); //登录成功信号
    void loginFail();                  //登录失败信号
  public:
    explicit Client(QObject *parent = nullptr);
    ~Client() override;

    int getServerNum(); //获取服务器数量
    QList<Server *> getServerList();
    Server *getServer(int index);                                                       //获取指定服务器对象
    void addServer(QString host, int port, QString nick, QString user, QString passwd); //添加服务器
  private slots:
    void addServer2List(Server *server);

  private:
    QList<Server *> _serverList; //服务器列表
};
