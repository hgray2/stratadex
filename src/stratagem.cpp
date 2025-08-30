#include "stratagem.hpp"

using namespace stratadex;
Stratagem::Stratagem(std::string name, std::vector<ComboDirection> combo) : name(name), combo(combo) 
{

}

Stratagem::Stratagem()
{
}

Stratagem::~Stratagem()
{
}

void Stratagem::setIconPath()
{
}

std::string stratadex::Stratagem::getName()
{
    return this->name;
}

std::vector<ComboDirection> stratadex::Stratagem::getComboSequence()
{
    return this->combo;
}
