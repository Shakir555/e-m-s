#include "clock.h"
#include <QTime>
#include <QDate>

Clock::Clock(QVBoxLayout* parentLayout)
{
    dateLabel = new QLabel(this);  // new label for the date
    dateLabel->setAlignment(Qt::AlignCenter);

    timeLabel = new QLabel(this);  // label belongs to this Clock widget
    timeLabel->setAlignment(Qt::AlignCenter);

    QFont font;
    font.setPointSize(15);
    font.bold();
    dateLabel->setFont(font);
    timeLabel->setFont(font);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Clock::updateTime);
    timer->start(1000);

    updateTime();

    // Use a layout to arrange the labels vertically inside this widget
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(dateLabel);
    layout->addWidget(timeLabel);
    setLayout(layout);

    // Add this Clock widget to the parent layout if provided
    if (parentLayout) {
        parentLayout->addWidget(this);
    }
}

void Clock::updateTime()
{
    dateLabel->setText(QDate::currentDate().toString("dddd, MMMM d, yyyy"));
    timeLabel->setText(QTime::currentTime().toString("hh:mm:ss"));
}
