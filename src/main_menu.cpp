#include <iostream>

#include <QPushButton>
#include <QStandardItemModel>
#include <QDebug>

#include "ui/ui_main_menu.h"
#include "main_menu.hpp"
#include "stratagem.hpp"
#include "quiz.hpp"

using namespace stratadex;
MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent), 
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    connect(ui->begin_button, &QPushButton::clicked, this, &MainMenu::BeginButtonCallback);

    Stratagem strat_anti_mat_rifle("Anti Material Rifle", {DOWN, LEFT, RIGHT, UP, DOWN});

    model = StratagemModel::getInstance();

    for ( std::pair<std::string, Stratagem> strat_entry : model->getAllStratagems()){
        new QListWidgetItem(strat_entry.first.c_str(), ui->stratListAvailable);
    }

    connect(ui->stratListAvailable, &QListWidget::itemClicked, this, &MainMenu::HandleStratagemClicked);

    connect(model, &StratagemModel::activeStratAdded, this, &MainMenu::handleActiveStratAdded);
}

MainMenu::~MainMenu()
{
}

void stratadex::MainMenu::BeginButtonCallback()
{

    /// TODO: Must have at least one stratagem selected
    emit BeginQuiz();
}

void MainMenu::HandleStratagemClicked(QListWidgetItem *item)
{
    model->appendActiveStrat(item->text().toStdString());
}

void MainMenu::handleActiveStratAdded(std::string strat_name)
{
    new QListWidgetItem(strat_name.c_str(), ui->stratListSelected);
}
