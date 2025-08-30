#ifndef STRAT_COMBO_EDIT
#define STRAT_COMBO_EDIT

#include <QLineEdit>

#include "combo_direction.hpp"

namespace stratadex{
    class StratComboEdit : public QLineEdit{

        Q_OBJECT

        public:

            StratComboEdit(QWidget *parent = nullptr);
            ~StratComboEdit();

            void keyPressEvent(QKeyEvent *event) override;

            std::vector<ComboDirection> getComboSequence();

        signals:
            void comboUpdated();

        public slots:
            void handleComboPassed();
            void handleComboFailed();

        private:
            std::vector<ComboDirection> combo_sequence;
    };
}
#endif