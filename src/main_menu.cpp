#include "main_menu.hpp"
#include "ui_main_menu.h"

using namespace stratadex;
MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent), 
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
}

