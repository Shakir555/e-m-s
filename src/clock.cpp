#include <QTime>
#include <QDate>
#include "clock.h"

Clock::Clock(QWidget* parent): QWidget(parent)
{
    dateLabel = new QLabel(this);
    dateLabel->setAlignment(Qt::AlignCenter);
    timeLabel = new QLabel(this);
    timeLabel->setAlignment(Qt::AlignCenter);
    QFont font;
    font.setPointSize(10);
    font.setBold(true);
    dateLabel->setFont(font);
    timeLabel->setFont(font);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Clock::updateTime);
    timer->start(1000);
    updateTime();
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(dateLabel);
    layout->addWidget(timeLabel);
    setLayout(layout);
}

void Clock::updateTime()
{
    dateLabel->setText(QDate::currentDate().toString("dddd, MMMM d, yyyy"));
    dateLabel->setStyleSheet("color: black");
    timeLabel->setText(QDate::currentDate().toString("hh:mm:ss"));
    timeLabel->setStyleSheet("color: black");
}