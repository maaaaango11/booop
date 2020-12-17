<<<<<<< HEAD
//
// Created by МаксиМ on 19.11.2020.
//

#include "UI.h"

void UI::draw(GameField* field){
    for(int i = 0; i<(field->getLen()); i++){
        for(int j = 0; j<(field->getHeight()); j++){
            std::cout<<field->out(field->getGrid()[i][j].getAlive())<<' ';
        }
        std::cout << std::endl;
    }
=======
//
// Created by МаксиМ on 19.11.2020.
//

#include "UI.h"

void UI::draw(GameField* field){
    for(int i = 0; i<(field->getLen()); i++){
        for(int j = 0; j<(field->getHeight()); j++){
            std::cout<<field->out(field->getGrid()[i][j].getAlive())<<' ';
        }
        std::cout << std::endl;
    }
>>>>>>> 476c3f8679e3a053f7623a934196f91509dd2542
}