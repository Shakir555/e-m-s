#ifndef CLOCK_H
#define CLOCK_H

#include <QLabel>
#include <QTimer>
#include <QWidget>
#include <QVBoxLayout>

class Clock: public QWidget
{
    Q_OBJECT

public:
    explicit Clock(QWidget* parent = nullptr);

private slots:
    void updateTime();
    
private:
    QLabel* dateLabel;
    QLabel* timeLabel;
    QTimer* timer;
};

#endif