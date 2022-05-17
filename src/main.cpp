#include "ui/widget.h"
#include <libcolutius/Message.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    auto *msg = new Message("hello");

    return QApplication::exec();
}