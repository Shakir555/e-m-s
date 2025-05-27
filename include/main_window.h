#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <vector>
#include "emp.h"

class Clock;
class PieChartOpenGLWidget;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(int screenWidth, int screenHeight, QWidget *parent = nullptr);

private:
    Clock* clockWidget;
    PieChartOpenGLWidget* pieChartWidget;
};

#endif // MAIN_WINDOW_H
