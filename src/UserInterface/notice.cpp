/**
 * @file Notice.cpp
 * @author Ccslykx (ccslykx@outlook.com)
 * @brief  IRC通知类实现
 * @version 0.2
 * @date 2022-7-8
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "ui/notice.h"

#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QPainter>
#include <QScreen>
#include <QGuiApplication>

Notice::Notice(QWidget *parent)
{
    init();
}

Notice::Notice(MsgInfo *info, quint32 displayTime, QWidget *parent)
{
    this->info = *info;
    this->displayTime = displayTime;
    init();
}

Notice::Notice(Message *message, quint32 displayTime, QWidget *parent)
{
    this->info = MsgInfo(*message);
    this->displayTime = displayTime;
    init();
}

Notice::~Notice()
{
    qDebug() << "[Notice] deconstructed";
}

void Notice::init()
{
    qDebug() << "[Notice] initializing ...";
    QLabel *nickname = new QLabel(info.nickname(), this);
    QLabel *content = new QLabel(info.content(), this);
    QPushButton *showButton = new QPushButton(tr("Show"), this);
    QPushButton *closeButton = new QPushButton(tr("Close"), this);
    QVBoxLayout *msglayout = new QVBoxLayout;
    QVBoxLayout *btnlayout = new QVBoxLayout;
    QHBoxLayout *mainlayout = new QHBoxLayout;

    this->timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &Notice::onClose);
    connect(showButton, &QPushButton::clicked, this, &Notice::onShowClicked);
    connect(closeButton, &QPushButton::clicked, this, &Notice::onClose);

    msglayout->addWidget(nickname);
    msglayout->addWidget(content);
    btnlayout->addWidget(showButton);
    btnlayout->addWidget(closeButton);
    mainlayout->addLayout(msglayout);
    mainlayout->addStretch();
    mainlayout->addLayout(btnlayout);

    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    qDebug() << "screen width: " << screenGeometry.width() << "screen height: " << screenGeometry.height();
    QRect noticeLocation = QRect(screenGeometry.width() - 432, 64, 400, 0);

    qDebug() << "notice rect" << noticeLocation;
    qDebug() << "notice width: " << noticeLocation.width() << "notice height: " << noticeLocation.height();

    this->setLayout(mainlayout);
    this->setFixedSize(noticeLocation.size());
    this->setWindowFlag(Qt::WindowType::FramelessWindowHint);
    this->setGeometry(noticeLocation);

    timer->setInterval(displayTime);
    timer->start();

    // 淡入淡出效果
    this->animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setDuration(333);

    this->show();
    this->isShow = true;
    animation->start();
}

void Notice::onShowClicked()
{
    qDebug() << "[Notice] showButton clicked";
    //this->widget->show(); //【怎么跳转到指定频道？需要修改widget？】
}

void Notice::onClose()
{
    qDebug() << "[Notice] close";
    if (isShow) this->close(); 
    isShow = false;
}

void Notice::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QColor("black"));
    painter.drawRect(0, 0, this->width()-1, this->height()-1);
}