#include <string>
#include <iostream>

enum Nucleotide{A, T, G, C};

class Rna{
    private char* first;
    private int len;
    Rna(Nucleotide a, int size);

    char* getFirst(){
        return this->first;
    }
    int getLen(){
        return this->len;
    }
};
Rna::Rna(Nucleotide a, int size) {
    char inp;
    char f;
    int divRem;
    switch(a){
        case 0:
            inp = 0x00;
        case 1:
            inp = 0x55;
        case 2:
            inp = 0xAA;
        case 3:
            inp = 0xFF;
    }
    f = inp;
    divRem = size % 4;
    if(divRem != 0){
        first = new char[(size/4)+1](inp);
        f << 2*(4-(divRem));
        first[size/4] = f;
    } else first = new char[size/4](inp);
    len = size;
}

//int whaa(char str, int pos){
//    if((pos<4)&&(pos>=0)){
//        str >> 2*(3-pos);
//        return (str & 0x3);
//    }
//}
//
//int main() {
//    int a = whaa(0xFF,3);
//    std::cout << a << std::endl;
//    return 0;
//}
