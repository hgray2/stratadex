#include "main_window.hpp"

#include "ui/ui_stratadex_main_window.h"

#include "main_menu.hpp"
#include "quiz.hpp"

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

    this->ui->setupUi(this);

    this->UpdateCurrentWidget(this->main_menu_widget);
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
    this->ui->horizontalLayout->addWidget(widget);
}
