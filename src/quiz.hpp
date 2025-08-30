#ifndef QUIZ_HPP
#define QUIZ_HPP

#include <random>

#include <QWidget>

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
            Quiz(QWidget *parent); 
            ~Quiz(); 

            // Sets up and starts a new quiz.
            void startQuiz();

        private:
            Ui::Quiz *ui;

            StratagemModel *model;

            Stratagem activeStratagem;

            std::default_random_engine gen;
            void pickNewStrat();

            void handleInputChanged(QString input);


    };

}

#endif