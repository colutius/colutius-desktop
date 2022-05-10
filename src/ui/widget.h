//
// Created by hgy on 2022/5/10.
//

#ifndef COLUTIUS_DESKTOP_WIDGET_H
#define COLUTIUS_DESKTOP_WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget() override;

private:
  Ui::Widget *ui;
};

#endif // COLUTIUS_DESKTOP_WIDGET_H
