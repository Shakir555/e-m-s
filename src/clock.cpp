#include "clock.h"
#include <QTime>
#include <QDate>
#include "gradientStyle.h"

Clock::Clock(QVBoxLayout* parentLayout)
{
    dateLabel = new QLabel(this);
    dateLabel->setAlignment(Qt::AlignCenter);

    timeLabel = new QLabel(this);
    timeLabel->setAlignment(Qt::AlignCenter);

    // Apply gold gradient background and white text color
    QString gold_gradient = GradientStyle::specifyGradientStyle(GradientStyle::TYPE_GOLD);
    QString stylesheet_gold = QString("background: %1; color: rgb(%2, %3, %4);")
                                .arg(gold_gradient)
                                .arg(GradientStyle::RGB_WHITE[0])
                                .arg(GradientStyle::RGB_WHITE[1])
                                .arg(GradientStyle::RGB_WHITE[2]);

    // Set black background, padding, and black border
    QString fullStyleSheet = QString(
        "background-color: black;"       // outer box color
        "padding: 10px;"                 // space inside the black box
        "border: 1px solid black;"       // black border
        "%1"                            // gold gradient background & white text
    ).arg(stylesheet_gold);

    this->setStyleSheet(fullStyleSheet);

    // Set bold, larger font for labels
    QFont font;
    font.setPointSize(10);
    font.setBold(true);
    // font.setFamily("Calibri");
    dateLabel->setFont(font);
    timeLabel->setFont(font);

    // Timer to update time every second
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Clock::updateTime);
    timer->start(1000);

    // Initial update
    updateTime();

    // Layout to arrange labels
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(dateLabel);
    layout->addWidget(timeLabel);
    setLayout(layout);

    // Add to parent layout if provided
    if (parentLayout) {
        parentLayout->addWidget(this);
    }
}

void Clock::updateTime()
{
    dateLabel->setText(QDate::currentDate().toString("dddd, MMMM d, yyyy"));
    dateLabel->setStyleSheet("color: black;");
    timeLabel->setText(QTime::currentTime().toString("hh:mm:ss"));
    timeLabel->setStyleSheet("color: black;");
}