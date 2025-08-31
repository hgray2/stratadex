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
    exerciseCount = 0;

    this->ui->inputLayout->addWidget(strat_combo_edit);

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

    this->ui->totalLabel->setText(QString::number(model->getNumExercises()));

    // Set the progress bar maximum
    this->ui->quizProgress->setMaximum(model->getNumExercises());
    this->ui->quizProgress->setValue(0);

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

    // This is a new exercise, increment.
    this->ui->correctLabel->setText(QString::number(this->exerciseCount));

    this->exerciseCount++;

    // Update the UI.
    QString strat_name = QString(activeStratagem.getName().c_str());
    this->ui->activeStratLabel->setText(strat_name);
}

void Quiz::handleComboUpdated()
{

    // QString activeName = QString(this->activeStratagem.getName().c_str());

    std::vector<ComboDirection> activeComboSequence = this->activeStratagem.getComboSequence();
    std::vector<ComboDirection> inputComboSequence = this->strat_combo_edit->getComboSequence();

    bool match = true;
    for(uint8_t i = 0; i < inputComboSequence.size(); i++){
        // If any input sequence mismatches a prefix of the active sequence, we report a failure.
        if(activeComboSequence.at(i) != inputComboSequence.at(i)){
            match = false;
            emit comboFailed();
        }
    }

    // If we matched so far AND the sequences are the same length, check if we passed.
    if(match && activeComboSequence.size() == inputComboSequence.size()){
        if(activeComboSequence == this->strat_combo_edit->getComboSequence()){
            qDebug() << "Match!\n";

            this->ui->quizProgress->setValue(exerciseCount);

            emit comboPassed();

            if(exerciseCount < this->model->getNumExercises()){
                pickNewStrat();
            } else{ 
                // Then that was the end, reset state and return to main menu.
                this->exerciseCount = 0;
                emit returnToMainMenu();
            }
        }
    }
}

void Quiz::displayPass()
{
    // this->strat_combo_edit->
}

void Quiz::displayFail()
{
}
