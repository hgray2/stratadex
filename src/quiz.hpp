#ifndef QUIZ_HPP
#define QUIZ_HPP

#include <random>

#include <QWidget>

#include "strat_combo_edit.hpp"
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

        private:
            Ui::Quiz *ui;

            StratComboEdit *strat_combo_edit;

            StratagemModel *model;

            Stratagem activeStratagem;

            size_t exerciseCount;

            std::default_random_engine gen;
            void pickNewStrat();

            void handleComboUpdated();

            /// @brief Updates the UI to indicate a passing combo.
            void displayPass();

            /// @brief Updates the UI to indicate a failing combo.
            void displayFail();
    };

}

#endif