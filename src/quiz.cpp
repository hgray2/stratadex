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

#include <unordered_map>

#include <QUrl>
#include <QKeyEvent>

#include "ui/ui_quiz.h"
#include "quiz.hpp"

using namespace stratadex;

Quiz::Quiz(QWidget *parent) : 
QWidget(parent), 
ui(new Ui::Quiz)
{
    this->ui->setupUi(this);
    this->model = StratagemModel::getInstance();

    exerciseCount = 0;

    /// Sounds
    this->inputSoundEffect.setSource(QUrl::fromLocalFile(":/resource/sounds/input_sound.wav"));
    this->inputSoundEffect.setLoopCount(1);
    this->inputSoundEffect.setVolume(0.25f);

    this->passSoundEffect.setSource(QUrl::fromLocalFile(":/resource/sounds/pass_sound.wav"));
    this->passSoundEffect.setLoopCount(1);
    this->passSoundEffect.setVolume(0.75f);

    this->failSoundEffect.setSource(QUrl::fromLocalFile(":/resource/sounds/fail_sound.wav"));
    this->failSoundEffect.setLoopCount(1);
    this->failSoundEffect.setVolume(0.25f);

    connect(this, &Quiz::comboUpdated, this, &Quiz::handleComboUpdated);
    connect(ui->quitButton, &QPushButton::clicked, this, [=](){ 
        this->exerciseCount = 0; 
        emit returnToMainMenu(); 
    });

    connect(this, &Quiz::comboPassed, this, &Quiz::handleComboPassed);
    connect(this, &Quiz::comboFailed, this, &Quiz::handleComboFailed);
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

    this->setFocus();
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
    std::vector<ComboDirection> activeComboSequence = this->activeStratagem.getComboSequence();
    std::vector<ComboDirection> inputComboSequence = this->combo_sequence;

    bool match = true;
    for(uint8_t i = 0; i < inputComboSequence.size(); i++){
        // If any input sequence mismatches a prefix of the active sequence, we report a failure.
        if(activeComboSequence.at(i) != inputComboSequence.at(i)){
            match = false;
            emit comboFailed();
        } else{
            // Update the arrow to indicate a matching prefix.
            QLabel *arrowLabel = static_cast<QLabel*>(this->ui->comboLayout->itemAt(i)->widget());

            ComboDirection direction = activeComboSequence.at(i);
            QIcon icon;
            switch(direction){
                case UP:
                    icon = QIcon(":/resource/icons/up_arrow_icon.png");
                    break;
                case DOWN:
                    icon = QIcon(":/resource/icons/down_arrow_icon.png");
                    break;
                case LEFT:
                    icon = QIcon(":/resource/icons/left_arrow_icon.png");
                    break;
                case RIGHT:
                    icon = QIcon(":/resource/icons/right_arrow_icon.png");
                    break;
            }  

            arrowLabel->setPixmap(icon.pixmap(QSize(25,25)));
        }
    }

    // If we matched so far AND the sequences are the same length, check if we passed.
    if(match && activeComboSequence.size() == inputComboSequence.size()){
        if(activeComboSequence == inputComboSequence){
            emit comboPassed();
        }
    } else{
        inputSoundEffect.play();
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
                icon = QIcon(":/resource/icons/up_arrow_inactive_icon.png");
                break;
            case DOWN:
                icon = QIcon(":/resource/icons/down_arrow_inactive_icon.png");
                break;
            case LEFT:
                icon = QIcon(":/resource/icons/left_arrow_inactive_icon.png");
                break;
            case RIGHT:
                icon = QIcon(":/resource/icons/right_arrow_inactive_icon.png");
                break;
        }  

        dirLabel->setPixmap(icon.pixmap(QSize(25,25)));

        this->ui->comboLayout->addWidget(dirLabel);
    }
}

void Quiz::handleComboPassed(){

    combo_sequence.clear();

    this->passSoundEffect.play();
    this->ui->quizProgress->setValue(exerciseCount);

    if(exerciseCount < this->model->getNumExercises()){
        pickNewStrat();
    } else{ 
        // Then that was the end, reset state and return to main menu.
        this->exerciseCount = 0;
        emit returnToMainMenu();
    }
}

void Quiz::handleComboFailed(){

    combo_sequence.clear();

    this->failSoundEffect.play();

    // Reset the combo icons
    clearComboIcons();
    addComboIcons();
}

void stratadex::Quiz::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
        case Qt::Key::Key_W:
            qDebug() << "UP";   
            this->combo_sequence.push_back(ComboDirection::UP);
            emit comboUpdated();
            break;
        case Qt::Key::Key_S:
            qDebug() << "DOWN";   
            this->combo_sequence.push_back(ComboDirection::DOWN);
            emit comboUpdated();
            break;
        case Qt::Key::Key_A:
            qDebug() << "LEFT";   
            this->combo_sequence.push_back(ComboDirection::LEFT);
            emit comboUpdated();
            break;
        case Qt::Key::Key_D:
            qDebug() << "RIGHT";   
            this->combo_sequence.push_back(ComboDirection::RIGHT);
            emit comboUpdated();
            break;
        default:
            break;
    }
}
