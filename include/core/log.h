#pragma once

#include <QObject>

class Log : public QObject
{
    explicit Log(QObject *parent = nullptr);
};
