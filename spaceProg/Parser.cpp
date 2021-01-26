//
// Created by МаксиМ on 26.01.2021.
//

#include "Parser.h"
#include <vector>
void Parser::parse() {
    std::string raw;
    std::vector<std::string> tokens;
    std::string del = " ";
    std::getline(std::cin, raw);
    int pos;
    while((pos = raw.find(del)) != std::string::npos){
        tokens.emplace_back(raw.substr(0, pos));
        //std::cout<<token<<std::endl;
        raw.erase(0, pos+del.length());
    }
    args->setCommand(tokens[0]);
    args->setParam1(tokens[1]);
    if(tokens.size() == 3) args->setParam2(stoi(tokens[2])); //somneniya
    //std::cout<<args->getParam2()<<std::endl;
}

Args* Parser::getArgs() {
    parse();
    return args;
}