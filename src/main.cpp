#include <ui/widget.h>
#include <QApplication>
#include <ui/systemtrayicon.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setQuitOnLastWindowClosed(false); //最后一个窗口关闭时，禁止退出应用程序
    Widget w;
    w.show();
    SystemTrayIcon trayIcon(&w);
    trayIcon.show();
    return QApplication::exec();
}