#pragma once

#include <QFile>
#include <QObject>
#include <QTextStream>
#include <QTime>

class Log : public QObject
{
  public:
    static void customMessageHandler(QtMsgType type, const QMessageLogContext &msg, const QString &string);
};
