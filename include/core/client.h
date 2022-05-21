#pragma once
#include <QObject>
#include <libcolutius/Channel.h>
#include <libcolutius/Message.h>
#include <libcolutius/Server.h>
#include <libcolutius/Session.h>
#include <libcolutius/User.h>

class Client : public QObject
{
  public:
    Client(QObject *parent = nullptr);
};
