#include <unordered_map>

#include "ui/ui_quiz.h"
#include "quiz.hpp"

using namespace stratadex;

Quiz::Quiz(QWidget *parent) : 
QWidget(parent), 
ui(new Ui::Quiz)
{
    this->ui->setupUi(this);
    this->model = StratagemModel::getInstance();

    strat_combo_edit = new StratComboEdit();

    this->ui->inputLayout->addWidget(strat_combo_edit);

    // this->ui->

    connect(strat_combo_edit, &StratComboEdit::comboUpdated, this, &Quiz::handleComboUpdated);

    connect(this, &Quiz::comboPassed, strat_combo_edit, &StratComboEdit::handleComboPassed);
    connect(this, &Quiz::comboFailed, strat_combo_edit, &StratComboEdit::handleComboFailed);
}

stratadex::Quiz::~Quiz()
{
}

void Quiz::startQuiz()
{
    pickNewStrat();

    // We want to give the edit focus immediately.
    this->strat_combo_edit->setFocus();
}

void stratadex::Quiz::pickNewStrat()
{
    auto activeStrats = model->getActiveStratagems();
    auto it = activeStrats.begin();

    // We want to pick a random value, so get an offset here.
    uint16_t N = activeStrats.size();
    std::uniform_int_distribution<int> dist(0, N - 1);
    int offset = dist(this->gen);

    // Advance the iterator by the offset.
    std::advance(it, offset);

    this->activeStratagem = it->second;

    // Update the UI.
    QString strat_name = QString(activeStratagem.getName().c_str());
    this->ui->activeStratLabel->setText(strat_name);
}

void Quiz::handleComboUpdated()
{

    // QString activeName = QString(this->activeStratagem.getName().c_str());

    std::vector<ComboDirection> activeComboSequence = this->activeStratagem.getComboSequence();

    if(activeComboSequence == this->strat_combo_edit->getComboSequence()){
        qDebug() << "Match!\n";

        emit comboPassed();
        pickNewStrat();
    }
}
