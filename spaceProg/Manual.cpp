//
// Created by МаксиМ on 26.01.2021.
//

#include "Manual.h"

void Manual::nextMove() {
    Args* args = parser.getArgs();
    for(auto const &item : commands){
        if(args->getCommand() == item.first){
            item.second->execute(args);
        }
    }
}
Manual::Manual(Parser &p) {
    parser = p;
}