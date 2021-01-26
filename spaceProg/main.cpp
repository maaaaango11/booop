#include <iostream>
#include "Engine.h"
//#include "Manual.h"
//#include "AutoScan.h"
//#include "AutoGrab.h"
#include "Collector.h"
#include "Bomber.h"
//#include "Parser.h"
int main() {
    Collector collector;
    Bomber bomber;
    //Parser parser{};
    //Manual manual(parser);
    //AutoScan autoScan;
    //AutoGrab autoGrab;
    Engine* engine = new Engine(collector, bomber);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}