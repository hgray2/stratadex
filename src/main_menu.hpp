/*
 * Copyright (C) 2025  Hayden Gray

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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

            void handleSearchFieldUpdated(QString query);
    };
}

#endif