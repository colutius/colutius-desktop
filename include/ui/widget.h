#pragma once

#include <QFile>
#include <QFontDatabase>
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

    void initUI(); //初始化界面

  private:
    Ui::Widget *ui;
};