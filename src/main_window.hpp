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

#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <QMainWindow>
#include <QStackedWidget>

#include "main_menu.hpp"
#include "quiz.hpp"

QT_BEGIN_NAMESPACE
namespace Ui{
    class StratadexMainWindow;
}
QT_END_NAMESPACE

namespace stratadex{
    class StratadexMainWindow : public QMainWindow{
        Q_OBJECT
        public:
            StratadexMainWindow(QWidget *parent);
            ~StratadexMainWindow();
        private:
            Ui::StratadexMainWindow *ui;

            QWidget *current_widget = nullptr;

            Quiz *quiz_widget;
            MainMenu *main_menu_widget;

            QStackedWidget *stacked_widget;

            void UpdateCurrentWidget(int index);
    };
}
#endif