#include "GameField.h"
#include "Commando.h"
#include "UI.h"
int main() {
    auto* field = new GameField(10, 10);
    auto* interface = new UI();
    auto* parser = new Commando();

    //std::cout << "Hello, World!" << std::endl;
    //return 0;
}