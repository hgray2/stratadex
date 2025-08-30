#include <QApplication>
#include <QWidget>

#include "main_window.hpp"

using namespace stratadex;
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    StratadexMainWindow window(nullptr);

    window.show();

    return app.exec();
}
