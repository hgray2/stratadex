#include <QApplication>
#include <QWidget>

#include "main_menu.hpp"

using namespace stratadex;
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainMenu main_menu(nullptr);

    main_menu.show();

    return app.exec();
}
