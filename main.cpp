#include <string>
#include <iostream>

enum Nucl{A, G, C, T};
//00 -- 11 A--T
//01 -- 10 G--C
size_t createWord(int a){
    if((a > 3)||(a<0)) return -1;
    size_t word;
    for(int i = 0; i < sizeof(size_t)/2; i++){ //+-1?
        word = word | a;
        word = word << 2;
    }
    return word;
}
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
    bool isComp(Rna* compTo);
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
    size_t f;
    size_t word = 0;
    int divRem;
    int divN;

    word = createWord(a);
    f = word;
    divRem = size % sizeof(size_t);
    divN = size / sizeof(size_t);
    if(divRem != 0){
        first = new size_t[(divN)+1](word);
        f << 2*(sizeof(size_t) - (divRem)); //
        first[divN] = f;
    } else first = new size_t[divN](word);
    len = size;
}
bool Rna::isComp(Rna* compTo) {
    int a = compTo->getLen();
    size_t* b = compTo->getFirst();
    if (a != len) return false;
    if (len%sizeof(size_t) != 0){
        a = len-1;
        if((b[a] ^ first[a]) != (createWord(3) << 2*(sizeof(size_t) - (len%sizeof(size_t))) ) ) return false; //last not full check
    }
    for (int i = 0; i<a; i++){
        if((b[i] ^ first[i]) != createWord(3)) return false; //all check
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
