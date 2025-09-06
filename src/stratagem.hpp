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

#ifndef STRATAGEMS_HPP
#define STRATAGEMS_HPP

#include <filesystem>
#include <vector>

#include <QString>

#include "combo_direction.hpp"

namespace fs = std::filesystem;

namespace stratadex{

    class Stratagem{
        public:
            Stratagem(std::string name, std::vector<ComboDirection> combo);
            Stratagem();
            ~Stratagem();

            // void set
            QString getIconPath();
            void setIconPath(QString path);

            std::string getName();

            std::vector<ComboDirection> getComboSequence();
        

        protected:
            // a name
            std::string name;
            // a stratagem code combo
            std::vector<ComboDirection> combo;

            QString iconPath;
    };
}

#endif