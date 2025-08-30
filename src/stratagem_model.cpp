#include "stratagem_model.hpp"

using namespace stratadex;

static StratagemModel *instance = nullptr;
StratagemModel *StratagemModel::getInstance()
{
    if(instance == nullptr){
        instance = new StratagemModel(nullptr);
    } 
    return instance;
}

std::unordered_map<std::string, Stratagem> stratadex::StratagemModel::getAllStratagems()
{
    return this->allStratagems;
}

std::unordered_map<std::string, Stratagem> StratagemModel::getActiveStratagems()
{
    return this->activeStratagems;
}

void StratagemModel::appendActiveStrat(std::string strat_name)
{
    // If we can find it here, continue.
    if(allStratagems.find(strat_name) != allStratagems.end()){
        Stratagem strat = allStratagems.at(strat_name);

        // If we can find it here, stop.
        if(activeStratagems.find(strat_name) == activeStratagems.end()){
            activeStratagems.insert({strat_name, strat});
            emit activeStratAdded(strat_name);
        }
    }
}

StratagemModel::StratagemModel(QObject *parent) :
QObject(parent)
{
    Stratagem strat_anti_mat_rifle("Anti Material Rifle", {DOWN, LEFT, RIGHT, UP, DOWN});
    Stratagem strat_resupply("Resupply", {DOWN, DOWN, RIGHT, UP});

    allStratagems.insert({strat_anti_mat_rifle.getName(), strat_anti_mat_rifle});
    allStratagems.insert({strat_resupply.getName(), strat_resupply});
}

StratagemModel::~StratagemModel()
{
}
