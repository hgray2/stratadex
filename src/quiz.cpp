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

    QIcon strat_icon = QIcon(activeStratagem.getIconPath());
    this->ui->activeStratIconLabel->setPixmap(strat_icon.pixmap(QSize(50,50)));

    // Icons for the combination
    clearComboIcons();
    addComboIcons();
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

            // Reset the combo icons
            clearComboIcons();
            addComboIcons();

            emit comboFailed();
        } else{
            // Update the arrow to indicate a matching prefix.
            QLabel *arrowLabel = static_cast<QLabel*>(this->ui->comboLayout->itemAt(i)->widget());

            ComboDirection direction = activeComboSequence.at(i);
            QIcon icon;
            switch(direction){
                case UP:
                    icon = QIcon(":/resource/up_arrow_icon.png");
                    break;
                case DOWN:
                    icon = QIcon(":/resource/down_arrow_icon.png");
                    break;
                case LEFT:
                    icon = QIcon(":/resource/left_arrow_icon.png");
                    break;
                case RIGHT:
                    icon = QIcon(":/resource/right_arrow_icon.png");
                    break;
            }  

            arrowLabel->setPixmap(icon.pixmap(QSize(25,25)));
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

void stratadex::Quiz::clearComboIcons()
{
    // Clear the combo layout
    size_t N = this->ui->comboLayout->count();
    for(size_t i = 0; i < N; i++){
        QLayoutItem *toRemove = this->ui->comboLayout->takeAt(0);
        this->ui->comboLayout->removeWidget(toRemove->widget());
        delete toRemove->widget();
    }
}

void stratadex::Quiz::addComboIcons()
{
    for(ComboDirection direction : activeStratagem.getComboSequence()){
        QLabel *dirLabel = new QLabel();
        QIcon icon;
        switch(direction){
            case UP:
                icon = QIcon(":/resource/up_arrow_inactive_icon.png");
                break;
            case DOWN:
                icon = QIcon(":/resource/down_arrow_inactive_icon.png");
                break;
            case LEFT:
                icon = QIcon(":/resource/left_arrow_inactive_icon.png");
                break;
            case RIGHT:
                icon = QIcon(":/resource/right_arrow_inactive_icon.png");
                break;
        }  

        dirLabel->setPixmap(icon.pixmap(QSize(25,25)));

        this->ui->comboLayout->addWidget(dirLabel);
    }
}
