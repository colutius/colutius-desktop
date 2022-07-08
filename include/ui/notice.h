/**
 * @file Notice.h
 * @author Ccslykx (ccslykx@outlook.com)
 * @brief  IRC通知类头文件
 * @version 0.2
 * @date 2022-7-8
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include "libcolutius/Message.h"
//#include "../../test/notice/Message.h" // 测试用
#include <QWidget>
#include <QPropertyAnimation>
#include <QTimer>

using Sender = Message::Sender;

struct MsgInfo // 为了 Sender 而继承
{
    MsgInfo() {};
    MsgInfo(Message &msg) : msg(&msg) {};

    QString session() { return msg->getSession(); };
    Sender sender() { return msg->getMsgSender(); };
    QString nickname() { return msg->getNick(); };
    QString content() { return msg->getMainMsg(); };
    QDateTime datetime() { return QDateTime::fromMSecsSinceEpoch(msg->getTime()); };

    Message *msg;
};

class Notice : public QWidget
{
    Q_OBJECT;

public:
    Notice(QWidget *parent = nullptr);
    Notice(MsgInfo*, quint32 displayTime = 5000, QWidget *parent = nullptr);
    Notice(Message*, quint32 displayTime = 5000, QWidget *parent = nullptr);
    ~Notice();

signals:
    void noticeClicked(MsgInfo *info = nullptr);

public slots:
    void onShowClicked();
    void onClose();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void init();

private:
    //Widget *widget;
    MsgInfo             info;
    quint32             displayTime;
    //QString icon = "";
    double              opcity = 0.0;
    QTimer              *timer = nullptr;
    QPropertyAnimation  *animation = nullptr;
    bool                isShow = false;
    //QRect               noticeLocation;
    /* 主题
    Theme *theme;
    */
};
