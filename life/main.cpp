#include "GameField.h"
#include "Commando.h"
//#include "UI.h"
int main() {
    auto* parser = new Commando();
    auto* field = new GameField(10, 10);
    field->setParser(parser);

    //std::cout << "Hello, World!" << std::endl;
    //return 0;
}
