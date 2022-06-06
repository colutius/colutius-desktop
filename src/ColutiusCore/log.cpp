#include "core/log.h"
#include <QApplication>

void Log::customMessageHandler(QtMsgType type, const QMessageLogContext &msg, const QString &string)
{
    QString time = QTime::currentTime().toString("[h:m:s ");
    QString txt;
    switch (type)
    {
        // 调试信息提示
    case QtDebugMsg:
        txt = time + "Debug]: " + string + "\n";
        break;
        // 一般的警告提示
    case QtWarningMsg:
        txt = time + "Warning]: " + string + "\n";
        break;
        // 严重错误提示
    case QtCriticalMsg:
        txt = time + "Critical]: " + string + "\n";
        break;
        // 致命错误提示
    case QtFatalMsg:
        txt = time + "Fatal]: " + string + "\n";
        abort();
        break;
    case QtInfoMsg:
        txt = time + "Info]: " + string + "\n";
        break;
    }
    // 写入文件

    QDir(QApplication::applicationDirPath()).mkdir("logs");
    QDir logPath = QDir(QApplication::applicationDirPath() + "/logs");
    QFile outFile(logPath.absoluteFilePath(QDate::currentDate().toString("yyyy-MM-dd.log")));
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt;
}
