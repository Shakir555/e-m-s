#include <QApplication>
#include <QScreen>
#include "main_window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int screenWidth = QGuiApplication::primaryScreen()->availableGeometry().width();

    MainWindow window(screenWidth);
    window.showFullScreen(); // or window.show() for normal window

    return app.exec();
}
