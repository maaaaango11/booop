#include <string>
#include <iostream>

enum Nucleotide{A, T, G, C};

class Rna{
    char* first;
    int len;
    Rna(Nucleotide a, int size);
};
//Rna::Rna(Nucleotide a, int size) {
//    first = calloc(sizeof(char)*((int)(size/4))+1);
//    len = size;
//}

int whaa(char str, int pos){
    if((pos<4)&&(pos>=0)){
        str = str >> 2*(3-pos);
        return (str & 0x3);
    }
    return -1;
}

int main() {
    int a = whaa(0xFF,3);
    std::cout << a << std::endl;
    return 0;
}
