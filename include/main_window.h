#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(int screenWidth, QWidget *parent = nullptr);
};

#endif // MAIN_WINDOW_H
