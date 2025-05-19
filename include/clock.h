#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>

class Clock : public QWidget
{
    Q_OBJECT

public:
    Clock(QVBoxLayout* parentLayout = nullptr);

private slots:
    void updateTime();

private:
    QLabel* timeLabel;
    QLabel* dateLabel;
    QTimer* timer;
};

#endif // CLOCK_H
