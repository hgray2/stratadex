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