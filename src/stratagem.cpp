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


    this->iconPath = QString(":/resource/icons/" + path_name + "_icon.png");
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
