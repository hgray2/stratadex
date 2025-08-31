#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <QWidget>
#include <QListWidgetItem>

#include "stratagem_model.hpp"

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
        
        signals:
            void BeginQuiz();

        private:
            /* data */
            Ui::MainMenu *ui;
            StratagemModel *model;

            void BeginButtonCallback();

            void handleAvailableStratClicked(QListWidgetItem *item);

            void handleActiveStratClicked(QListWidgetItem *item);

            void handleActiveStratAdded(std::string strat_name);

            void handleNumExecChanged(int num_exec);
    };
}

#endif