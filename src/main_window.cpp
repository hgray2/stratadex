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

#include <QLabel>

#include "main_window.hpp"
#include "main_menu.hpp"
#include "quiz.hpp"
#include "project_config.h"
#include "ui/ui_stratadex_main_window.h"

using namespace stratadex;
StratadexMainWindow::StratadexMainWindow(QWidget *parent) : 
QMainWindow(parent),
ui(new Ui::StratadexMainWindow)
{
    this->ui->setupUi(this);
    this->main_menu_widget = new MainMenu(this);
    this->quiz_widget = new Quiz(this);

    this->stacked_widget = new QStackedWidget(this);
    QVBoxLayout *stacked_layout = new QVBoxLayout(stacked_widget);

    this->stacked_widget->addWidget(main_menu_widget);
    this->stacked_widget->addWidget(quiz_widget);

    this->centralWidget()->layout()->addWidget(stacked_widget);

    QObject::connect(
        this->main_menu_widget, 
        &MainMenu::BeginQuiz, 
        this, 
        [=](){ 
            this->UpdateCurrentWidget(1); 
            quiz_widget->startQuiz();
        }
    );

    QObject::connect(
        this->quiz_widget, 
        &Quiz::returnToMainMenu, 
        this, 
        [=](){ 
            this->UpdateCurrentWidget(0); 
        }
    );


    this->UpdateCurrentWidget(0);

    /// Status bar
    QLabel *version_label = new QLabel(QString("version %1.%2.%3").arg(MAJOR_VERSION).arg(MINOR_VERSION).arg(PATCH_VERSION));
    this->statusBar()->addWidget(version_label);
}

stratadex::StratadexMainWindow::~StratadexMainWindow()
{
}

void StratadexMainWindow::UpdateCurrentWidget(int index)
{
    this->stacked_widget->setCurrentIndex(index);
}
