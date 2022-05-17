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
  public:
    explicit Session(QObject *parent = nullptr);
    ~Session() override;

  private:
    QList<Message *> _messageList; //消息列表
};
