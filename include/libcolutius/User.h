/**
 * @file User.h
 * @author ambition_echo (ambition_echo@outlook.com)
 * @brief  IRC用户类头文件
 * @version 0.1
 * @date 2022-05-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include "Session.h"
/**
 * @brief IRC用户类
 *
 */
class User : public Session
{
    Q_OBJECT
  public:
    explicit User(QString name, Session *parent = nullptr);
    ~User() override;

    QString getType();
};
