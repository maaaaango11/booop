//
// Created by МаксиМ on 19.11.2020.
//
//#include "GameField.h"
#include "UI.h"


std::istream& operator>>(std::istream &in, const GameField &gameField) {
    for(int i = 0; i<gameField.len; i++){
        for(int j = 0; j<gameField.height; j++){

        }
    }
    return in;
}

void UI::draw(const GameField& field){
    //std::cout << field;
}
void UI::draw(const GameField& field, FILE* file){
    //reinterpret_cast<int &>(file) << field;
}
Cell** UI::fileRead(FILE *file) {
    Cell** grid;
//    file>> grid;
}