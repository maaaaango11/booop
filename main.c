#include <string>
#include <iostream>

enum Nucleotide{A, G, C, T};
//00 -- 11 A--T
//01 -- 10 G--C
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
    bool isComp(Rna compTo);
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
bool Rna::isComp(Rna compTo) {
    int a = compTo.getLen();
    char* b = compTo.getFirst();
    if (a != len) return 0;
    if (len%4 != 0){
        a = len-1;
        if((b[a] ^ first[a]) != (0xFF << 2*(4 - (len%4)) ) ) return 0; //last not full check
    }
    for (int i = 0; i<a; i++){
        if(b[i] ^ first[i] != 0xFF) return 0; //all check
    }
    return 1;
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
