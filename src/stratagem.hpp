#ifndef STRATAGEMS_HPP
#define STRATAGEMS_HPP

#include <filesystem>
#include <vector>

#include "combo_direction.hpp"

namespace fs = std::filesystem;

namespace stratadex{

    class Stratagem{
        public:
            Stratagem(std::string name, std::vector<ComboDirection> combo);
            Stratagem();
            ~Stratagem();

            // void set
            void setIconPath();

            std::string getName();
        

        protected:
            // a name
            std::string name;
            // a stratagem code combo
            std::vector<ComboDirection> combo;
    };
}

#endif