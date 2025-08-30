#include "strat_combo_edit.hpp"

#include <QKeyEvent>

using namespace stratadex;
StratComboEdit::StratComboEdit(QWidget *parent) :
QLineEdit(parent)
{
}

StratComboEdit::~StratComboEdit()
{
}

std::vector<ComboDirection> StratComboEdit::getComboSequence(){
    return this->combo_sequence;
}

void StratComboEdit::handleComboPassed()
{
    this->combo_sequence.clear();
}

void StratComboEdit::handleComboFailed()
{
    this->combo_sequence.clear();
}

void StratComboEdit::keyPressEvent(QKeyEvent *event)
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
