/**
 * @file Channel.h
 * @author ambition_echo (ambition_echo@outlook.com)
 * @brief  IRC频道类头文件
 * @version 0.1
 * @date 2022-05-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include "Session.h"
/**
 * @brief IRC频道类
 *
 */
class Channel : public Session
{
    Q_OBJECT
  public:
    explicit Channel(QString name, Session *parent = nullptr);
    ~Channel() override;

    QString getType();
    void quit();
};
