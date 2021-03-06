#pragma once

#include <QDir>
#include <QFile>
#include <QObject>
#include <QTextStream>
#include <QTime>
#include <core/log.h>

class Log : public QObject
{
  public:
    static void customMessageHandler(QtMsgType type, const QMessageLogContext &msg, const QString &string);
};
