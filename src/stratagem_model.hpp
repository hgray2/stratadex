#ifndef STRATAGEM_MODEL
#define STRATAGEM_MODEL

#include <vector>
#include <unordered_map>

#include <QObject>

#include "stratagem.hpp"

namespace stratadex{

    class StratagemModel : public QObject{

        Q_OBJECT
        public:
            std::unordered_map<std::string, Stratagem> getAllStratagems();
            std::unordered_map<std::string, Stratagem> getActiveStratagems();

            size_t getNumExercises();
            void setNumExercises(size_t numExercises);

            static StratagemModel *getInstance();

            /// @brief Appends the stratagem with name 'strat_name' to the vector
            /// of active stratagems.
            /// @param strat_name The name of the stratagem to append.
            void appendActiveStrat(std::string strat_name);

            /// @brief Removes the strat with the name 'strat_name'
            /// @param strat_name The name of the stratagem to remove.
            void removeActiveStrat(std::string strat_name);

        signals:
            void activeStratAdded(std::string strat_name);

        private:
            StratagemModel(QObject *parent);// private ctor and dtor
            ~StratagemModel();

            // Map of all stratagems.
            std::unordered_map<std::string, Stratagem> allStratagems;

            // Map of all the stratagems currently selected or in play.
            std::unordered_map<std::string, Stratagem> activeStratagems;

            size_t numberOfExercises;
    };
}

#endif