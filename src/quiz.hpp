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

#ifndef QUIZ_HPP
#define QUIZ_HPP

#include <random>

#include <QWidget>
#include <QSoundEffect>

#include "stratagem_model.hpp"

QT_BEGIN_NAMESPACE
namespace Ui{
    class Quiz;
}
QT_END_NAMESPACE

namespace stratadex{

    class Quiz: public QWidget
    {
        Q_OBJECT
        public:
            Quiz(QWidget *parent = nullptr); 
            ~Quiz(); 

            // Sets up and starts a new quiz.
            void startQuiz();

        signals:
            void comboPassed();
            void comboFailed();

            void returnToMainMenu();

            void comboUpdated();

        public slots:
            void handleComboPassed();
            void handleComboFailed();

        private:
            Ui::Quiz *ui;

            StratagemModel *model;

            Stratagem activeStratagem;

            size_t exerciseCount;

            QSoundEffect passSoundEffect;
            QSoundEffect inputSoundEffect;
            QSoundEffect failSoundEffect;

            std::default_random_engine gen;
            void pickNewStrat();

            void handleComboUpdated();

            /// @brief Updates the UI to indicate a passing combo.
            void displayPass();

            /// @brief Updates the UI to indicate a failing combo.
            void displayFail();

            /// @brief Resets the icons for the current stratagem combo to inactive.
            void addComboIcons();

            /// @brief Removes all of the icons for the current stratagem combo.
            void clearComboIcons();

            std::vector<ComboDirection> combo_sequence;

        protected:
            void keyPressEvent(QKeyEvent *event) override;
    };

}

#endif