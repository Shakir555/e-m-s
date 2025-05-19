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
    explicit Clock(QVBoxLayout* parentLayout = nullptr);

private slots:
    void updateTime();

private:
    QLabel* dateLabel;
    QLabel* timeLabel;
    QTimer* timer;
};

#endif // CLOCK_H
