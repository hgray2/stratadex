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