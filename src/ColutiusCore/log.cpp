#include <core/log.h>

void Log::customMessageHandler(QtMsgType type, const QMessageLogContext &msg, const QString &string)
{
    QString time = QTime::currentTime().toString("[h:m:s ");
    QString txt;
    switch (type)
    {
        //调试信息提示
    case QtDebugMsg:
        txt = time + "Debug]: " + string + "\n";
        break;
        //一般的警告提示
    case QtWarningMsg:
        txt = time + "Warning]: " + string + "\n";
        break;
        //严重错误提示
    case QtCriticalMsg:
        txt = time + "Critical]: " + string + "\n";
        break;
        //致命错误提示
    case QtFatalMsg:
        txt = time + "Fatal]: " + string + "\n";
        abort();
    }
    //写入文件
    QFile outFile("Colutius_log.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt;
}