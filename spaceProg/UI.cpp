//
// Created by МаксиМ on 26.01.2021.
//

#include "UI.h"

void UI::draw(Map &map, int x, int y) {
    for(int i = 0; i<map.getLen(); ++i){
        for(int j = 0; j<map.getHeight(); j++){
            //if(i == x && j == y) {std::cout<<'*';} else {
                std::cout<<map.getMap()[i][j];
            //}
        }
        std::cout<<std::endl;
    }
}