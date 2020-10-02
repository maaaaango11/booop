#include <string>
#include <iostream>

enum Nucl{A, G, C, T};
//00 -- 11 A--T
//01 -- 10 G--C
class Rna{
private:
    size_t* first;
    int len;
public:
    Rna(Nucl a, int size);

    size_t* getFirst(){
        return this->first;
    }
    int getLen(){
        return this->len;
    }
    bool isComp(Rna compTo);
//    class Reference{
//        size_t num;
//        Rna& rna;
//        Reference(size_t n, Rna r){
//         num = n;
//         rna = r;
//        };
//        Reference& operator=(Nucl n){
//            
//        }
//    };
//    Reference operator[] (size_t num){
//        return Reference(num, *this);
//    }
};

Rna::Rna(Nucl a, int size) {
    size_t inp = 0x00;
    size_t f;
    int divRem;
    int divN;
    switch(a){
        case 0:
            inp = 0x00;
            break;
        case 1:
            inp = 0x55;
            break;
        case 2:
            inp = 0xAA;
            break;
        case 3:
            inp = 0xFF;
            break;
    }
    f = inp;
    divRem = size % sizeof(size_t);
    divN = size / sizeof(size_t);
    if(divRem != 0){
        first = new char[(divN)+1](inp);
        f << 2*(sizeof(size_t) - (divRem)); //
        first[divN] = f;
    } else first = new char[divN](inp);
    len = size;
}
bool Rna::isComp(Rna compTo) {
    int a = compTo.getLen();
    size_t* b = compTo.getFirst();
    if (a != len) return false;
    if (len%sizeof(size_t) != 0){
        a = len-1;
        if((b[a] ^ first[a]) != (0xFF << 2*(sizeof(size_t) - (len%sizeof(size_t))) ) ) return false; //last not full check
    }
    for (int i = 0; i<a; i++){
        if((b[i] ^ first[i]) != 0xFF) return false; //all check
    }
    return true;
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
int main(){
    //Rna
}
