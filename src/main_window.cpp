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
    this->main_menu_widget = new MainMenu(nullptr);
    this->quiz_widget = new Quiz(nullptr);

    QObject::connect(
        this->main_menu_widget, 
        &MainMenu::BeginQuiz, 
        this, 
        [=](){ 
            this->UpdateCurrentWidget(this->quiz_widget); 
            quiz_widget->startQuiz();
        }
    );

    QObject::connect(
        this->quiz_widget, 
        &Quiz::returnToMainMenu, 
        this, 
        [=](){ 
            this->UpdateCurrentWidget(this->main_menu_widget); 
        }
    );

    this->ui->setupUi(this);

    this->UpdateCurrentWidget(this->main_menu_widget);


    /// Status bar

    QLabel *version_label = new QLabel(QString("version %1.%2.%3").arg(MAJOR_VERSION).arg(MINOR_VERSION).arg(PATCH_VERSION));
    this->statusBar()->addWidget(version_label);
}

stratadex::StratadexMainWindow::~StratadexMainWindow()
{
}

void StratadexMainWindow::UpdateCurrentWidget(QWidget *widget)
{
    if(current_widget){
        this->ui->horizontalLayout->removeWidget(current_widget);
        this->current_widget->setVisible(false);
    }
    current_widget = widget;
    current_widget->setVisible(true);
    this->ui->horizontalLayout->addWidget(widget);
}
