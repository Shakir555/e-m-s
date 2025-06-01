#include <QApplication>
#include <QScreen>
#include "database.h"
#include "main_window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    initializeDatabase();
    QScreen *screen = QGuiApplication::primaryScreen();
    int screenWidth = screen->availableGeometry().width();
    int screenHeight = screen->availableGeometry().height();
    MainWindow window(screenWidth, screenHeight);
    window.showFullScreen();
    return app.exec();
}
