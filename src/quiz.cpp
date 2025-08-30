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

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &Quiz::handleInputChanged);
}

stratadex::Quiz::~Quiz()
{
}

void Quiz::startQuiz()
{

    pickNewStrat();




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

void Quiz::handleInputChanged(QString input)
{

    QString activeName = QString(this->activeStratagem.getName().c_str());
    if(input.compare(activeName) == 0){
        qDebug() << "Match!\n";
        pickNewStrat();
    }

}
