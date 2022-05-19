#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include <QWidget>

class Notify : public QWidget
{
    Q_OBJECT
  signals:
    void disappeared();

  public:
    explicit Notify(int displayTime, QWidget *parent = nullptr);

    void setIcon(const QString &value);

    void setTitle(const QString &value);

    void setBody(const QString &value);

    void setUrl(const QString &value);

    void showGriant();

  private:
    int displayTime;

    QString icon;
    QString title;
    QString body;
    QString url;

    QLabel *backgroundLabel;
    QLabel *iconLabel;
    QLabel *titleLabel;
    QLabel *bodyLabel;

    QPushButton *closeBtn;

    void hideGriant();

    void mousePressEvent(QMouseEvent *event);
};
