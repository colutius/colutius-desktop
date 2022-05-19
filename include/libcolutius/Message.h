/**
 * @file Message.h
 * @author ambition_echo (ambition_echo@outlook.com)
 * @brief  IRC消息类头文件
 * @version 0.1
 * @date 2022-05-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <QDebug>
#include <QObject>
#include <QRegularExpression>
#include <QTime>
#include <QtGui/QValidator>
/**
 * @brief IRC消息类
 * 将原始数据传入其中，由该类对接收到的消息进行解析、分类、格式化
 */
class Message : public QObject
{
    Q_OBJECT
  public:
    /**
     * @brief 消息类型
     */
    enum Type
    {
        None = 0,     ///<未知消息
        Ping = 1,     ///<服务器定期Ping消息
        Error = 3,    ///<报错信息
        Notice = 4,   ///<注意信息
        Join = 5,     ///<加入信息
        Quit = 6,     ///<退出频道消息
        Nick = 7,     ///<昵称相关信息
        Kick = 8,     ///<踢人信息
        Num = 9,      ///<数字类信息，相当于状态码
        Private = 10, ///<私信消息
        Channel = 11, ///<正常频道消息
    };
    /**
     * @brief 消息发送者
     */
    enum Sender
    {
        Server = 1, ///<服务器发送的消息
        User = 2,   ///<其他用户发送的消息
        Owner = 3,  ///<用户自己发送的消息
    };
    explicit Message(QString msg = "", Sender sender = Sender::User, QObject *parent = nullptr);
    ~Message() override;

    void setRawMsg(QString msg);      //设置原始数据
    QString getRawMsg();              //获取原始数据
    Type getMsgType();                //获取消息类型
    void setMsgSender(Sender sender); //设置消息发送者
    Sender getMsgSender();            //获取消息发送者
    void parse();                     //解析消息原始数据
    QString getMainMsg();             //获取主体信息
    void setMsgType(Type type);       //设置消息类型
    void setNick(QString nick);       //设置消息发送者昵称
    QString getSession();             //获取会话名称
    QString getNick();                //获取发送者昵称
    QString getIp();                  //获取发送者IP
    int getNum() const;               //获取数字
    QTime getTime();                  //获取消息发送时间
    void setSession(QString session);//设置消息所在会话

  private:
    void parseMsgSender(const QString &msg);          //解析消息发送者信息
    void parseMainMsg(const QString &msg, int index); //解析消息的主要信息
    void setTime();                                   //设置当前时间
    Type _type = None;                                //消息类型
    Sender _sender;                                   //消息发送者
    QString _rawMsg;                                  //原始数据
    QString _mainMsg;                                 //消息主体信息
    QString _session;                                 //消息所在会话
    QString _nick;                                    //消息发送者昵称
    QString _ip;                                      //消息发送者ip
    int _num;                                         //数字指令消息的数字
    QTime _msgTime;                                   //消息发送/接收时间
};
