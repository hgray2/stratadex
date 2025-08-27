#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui{
    class MainMenu;
}
QT_END_NAMESPACE

namespace stratadex{


    class MainMenu: public QWidget
    {
        Q_OBJECT
        public:
            MainMenu(QWidget *parent); 
            ~MainMenu(); 

        private:
            /* data */
            Ui::MainMenu *ui;
    };

}

#endif