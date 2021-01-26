#include <iostream>
#include "Engine.h"
#include "Manual.h"
#include "AutoScan.h"
#include "AutoGrab.h"
#include "Collector.h"
#include "Parser.h"
int main() {
    Collector collector;
    Parser parser{};
    Manual manual(parser);
    AutoScan autoScan;
    AutoGrab autoGrab;
    Engine* engine = new Engine(collector, manual, autoScan, autoGrab);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}