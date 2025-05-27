#include <QApplication>
#include <QScreen>
#include "main_window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Get screen dimensions
    QScreen *screen = QGuiApplication::primaryScreen();
    int screenWidth = screen->availableGeometry().width();
    int screenHeight = screen->availableGeometry().height();

    // Pass both width and height to MainWindow constructor
    MainWindow window(screenWidth, screenHeight);
    window.showFullScreen(); // or window.show() for normal window

    return app.exec();
}
