/**
 * @file Session.h
 * @author ambition_echo (ambition_echo@outlook.com)
 * @brief  IRC会话类头文件
 * @version 0.1
 * @date 2022-05-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include "Message.h"
#include <QObject>
/**
 * @brief IRC会话类
 *
 */
class Session : public QObject
{
    Q_OBJECT
  signals:
    void newMsg(); ///<新消息
  public:
    explicit Session(QString name, QObject *parent = nullptr);
    ~Session() override;

    QString getName();                 //获取会话名称
    void addMessage(Message *message); //添加消息
    QString getType();                 //获取会话类型
    QList<Message *> getMessageList(); //获取消息列表
    Message *getMessage(int index);    //获取指定消息实例
    int getMessageNum();               //获取消息数量
  protected:
    QList<Message *> _messageList; //消息列表
    QString _name;                 //会话名称
};
