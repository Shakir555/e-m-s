#include <QOpenGLFunctions>
#include <QPainter>
#include <QPaintEngine>
#include <QtMath>
#include "piechart.h"

PieChartOpenGLWidget::PieChartOpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent)
{
    //Pie Chart OpenGL Class
}

void PieChartOpenGLWidget::setDepartmentData(const QMap<QString, int>& data)
{
    departmentCounts = data;
    update();
}

void PieChartOpenGLWidget::initializeGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void PieChartOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void PieChartOpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    if (departmentCounts.isEmpty())
    {
        return;
    }
    QRectF rect(width() / 2 - 150, height() / 2 - 150, 300, 300);
    int total = 0;
    for (auto count:departmentCounts)
    {
        total += count;
    }
    float startAngle = 0.0f;
    int colorIndex = 0;
    const QColor colors[] =
    {
        Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::cyan, Qt::magenta
    };
    for (auto it = departmentCounts.begin(); it != departmentCounts.end(); ++it, ++colorIndex) 
    {
        float percentage = static_cast<float>(it.value()) / total;
        float spanAngle = percentage * 360.0f;
        painter.setPen(QPen(Qt::black, 2));
        painter.setBrush(colors[colorIndex % 6]);
        painter.drawPie(rect, startAngle * 16, spanAngle * 16);
        startAngle += spanAngle;
    }
    painter.end();
}