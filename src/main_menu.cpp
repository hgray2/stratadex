#include <iostream>

#include <QPushButton>
#include <QStandardItemModel>
#include <QLineEdit>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QDebug>
#include <QFont>

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

    model = StratagemModel::getInstance();

    model->setNumExercises(ui->numExecSpinBox->value());

    QImage *image = new QImage(":/resource/anti_material_file_icon.png");

    // Configure the strat lists
    QSize stratIconSize = QSize(50,50);
    QFont stratFont("Arial", 10, QFont::Bold);

    ui->stratListAvailable->setIconSize(stratIconSize);
    ui->stratListAvailable->setFont(stratFont);
    

    ui->stratListSelected->setIconSize(stratIconSize);
    ui->stratListSelected->setFont(stratFont);

    for ( std::pair<std::string, Stratagem> strat_entry : model->getAllStratagems()){
        Stratagem strat = strat_entry.second;

        QIcon strat_icon = QIcon(strat.getIconPath());
        QString strat_name = QString(strat.getName().c_str());

        QListWidgetItem *item = new QListWidgetItem(strat_icon, strat_name);

        ui->stratListAvailable->addItem(item);
    }

    connect(ui->begin_button, &QPushButton::clicked, this, &MainMenu::BeginButtonCallback);

    connect(ui->stats_button, &QPushButton::clicked, this, [=](){
        QMessageBox *dialog = new QMessageBox();
        dialog->setText("This feature has not been implemented yet.");
        dialog->show();
    });



    connect(ui->stratListAvailable, &QListWidget::itemClicked, this, &MainMenu::handleAvailableStratClicked);

    connect(ui->stratListSelected, &QListWidget::itemClicked, this, &MainMenu::handleActiveStratClicked);

    connect(ui->numExecSpinBox, &QSpinBox::valueChanged, this, &MainMenu::handleNumExecChanged);

    connect(ui->search_line_edit, &QLineEdit::textChanged, this, &MainMenu::handleSearchFieldUpdated);

    connect(model, &StratagemModel::activeStratAdded, this, &MainMenu::handleActiveStratAdded);

}

MainMenu::~MainMenu()
{
}

void stratadex::MainMenu::BeginButtonCallback()
{

    /// TODO: Must have at least one stratagem selected
    if(ui->stratListSelected->count() > 0){
        emit BeginQuiz();
    } else{
        QMessageBox *dialog = new QMessageBox();
        dialog->setText("No Stratagems Selected");
        dialog->setInformativeText("Please select at least 1 stratagem to begin.");
        dialog->addButton("Ok", QMessageBox::ButtonRole::AcceptRole);
        dialog->exec();
    }
}

void MainMenu::handleAvailableStratClicked(QListWidgetItem *item)
{
    model->appendActiveStrat(item->text().toStdString());
}

void MainMenu::handleActiveStratClicked(QListWidgetItem *item){

    model->removeActiveStrat(item->text().toStdString());
    this->ui->stratListSelected->removeItemWidget(item);
    delete item;
}

void MainMenu::handleActiveStratAdded(std::string strat_name)
{
    Stratagem strat = model->getAllStratagems().at(strat_name);

    QIcon strat_icon = QIcon(strat.getIconPath());
    QString q_strat_name = QString(strat.getName().c_str());

    QListWidgetItem *item = new QListWidgetItem(strat_icon, q_strat_name);

    ui->stratListSelected->addItem(item);
}

void stratadex::MainMenu::handleNumExecChanged(int num_exec)
{
    this->model->setNumExercises(num_exec);
}

void stratadex::MainMenu::handleSearchFieldUpdated(QString query)
{
    for(size_t i = 0; i < ui->stratListAvailable->count(); i++){
        QListWidgetItem *item = ui->stratListAvailable->item(i);

        if(item->text().contains(query, Qt::CaseInsensitive)){
            item->setHidden(false);
        } else{
            item->setHidden(true);
        }
    }
}
