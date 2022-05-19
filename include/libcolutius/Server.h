/**
 * @file Server.h
 * @author ambition_echo (ambition_echo@outlook.com)
 * @brief  IRC服务器类头文件
 * @version 0.1
 * @date 2022-05-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include "Channel.h"
#include "Message.h"
#include "Session.h"
#include "User.h"
#include <QDebug>
#include <QHostInfo>
#include <QObject>
#include <QSslSocket>
#include <QTcpSocket>
/**
 * @brief IRC服务器类
 *
 */
class Server : public QObject
{
    Q_OBJECT
  signals:
    void loginSuccess();                   ///<服务器连接成功
    void loginFail();                      ///<服务器连接失败
    void disconnected();                   ///<服务器断开连接
    void networkError();                   ///<网络未连接
    void networkOk();                      ///<网络已连接
    void addSessionSucess();               ///<会话加入成功
    void addSessionCallBack(QString name); ///<内部信号
  public:
    /**
     * @brief 服务器当前状态
     */
    enum Status
    {
        Connected,    ///<服务器已连接
        Disconnected, ///<服务器断开连接
    };
    /**
     * 服务器连接类型
     */
    enum Type
    {
        Tcp, ///< TCP Socket
        Ssl, ///< SSL Socket
    };
    explicit Server(Type type = Tcp, QString host = "", int port = 0, QString nick = "", QString user = "",
                    QString passwd = "", QObject *parent = nullptr);
    ~Server() override;
    void login();                         //连接并登录服务器
    void disconnect();                    //断开连接
    void setHost(QString host);           //设置服务器地址
    void setPort(int port);               //设置端口
    void setNick(QString nick);           //设置昵称
    void setUser(QString user);           //设置用户名
    void setPasswd(QString passwd);       //设置密码
    QString getNick();                    //获取昵称
    QString getHost();                    //获取服务器地址
    void receiveData();                   //接收数据
    void addSession(const QString &name); //添加会话
    QList<Message *> getMessageList();    //获取消息列表
    Message *getMessage(int index);       //获取消息实例
    Session *getSession(int index);       //获取会话实例
    Session *getSession(QString name);    //获取会话实例
    QList<Session *> getSessionList();    //获取会话列表
    int getMessageNum();                  //获取消息数目
    int getSessionNum();                  //获取会话数目
    void sendMsg(Message *message);       //向指定会话发送消息
  private slots:
    void _checkNetWork(const QHostInfo &host); //检查网络连接情况
    void _addSessionCallBack(QString name);    //添加会话回调

  private:
    void _sendData(const QString &data); //向服务器发送数据
    void _initConnect();                 //初始化信号槽
    void _connect();                     //连接到服务器
    void _login();                       //登录到服务器
    QList<Session *> _sessionList;       //会话列表
    QList<Message *> _messageList;       //服务器消息列表
    QString _host;                       //服务器地址
    int _port = 0;                       //服务器端口号
    QString _nick;                       //昵称
    QString _user;                       //用户名
    QString _passwd = "";                //密码
    QAbstractSocket *_socket;
    Status _status; //服务器状态
    Type _type;     //服务器连接类型
};
