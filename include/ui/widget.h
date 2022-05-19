#pragma once

#include <QWidget>

namespace Ui
{
class Widget;
}

class Widget : public QWidget
{
  Q_OBJECT

  public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

  private:
    Ui::Widget *ui;
};