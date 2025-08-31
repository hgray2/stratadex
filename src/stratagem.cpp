#include "stratagem.hpp"

#include <QStringList>

using namespace stratadex;
Stratagem::Stratagem(std::string name, std::vector<ComboDirection> combo) : name(name), combo(combo) 
{

    QString path_name = QString(name.c_str());

    // Get the name into the correct format for the path.
    QStringList path_name_list = path_name.split(" ");

    for (size_t i = 0; i < path_name_list.count(); i++){
        QString tmp = path_name_list.back();
        path_name_list.pop_back();
        path_name_list.push_front(tmp.toLower());
    }

    path_name = path_name_list.join("_");


    this->iconPath = QString(":/resource/" + path_name + "_icon.png");
}

Stratagem::Stratagem()
{
}

Stratagem::~Stratagem()
{
}

QString Stratagem::getIconPath()
{
    return this->iconPath;
}


void Stratagem::setIconPath(QString path)
{
    this->iconPath = path;
}

std::string stratadex::Stratagem::getName()
{
    return this->name;
}

std::vector<ComboDirection> stratadex::Stratagem::getComboSequence()
{
    return this->combo;
}
