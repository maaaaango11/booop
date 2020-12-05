#include <string>
#ifndef rna_h
#include "rna.h"
#endif
#define BYTES 8
#define CAP BYTES*sizeof(size_t)

size_t createWord(int a){
    if((a > 3)||(a<0)) return -1;
    size_t word = a;
    for(size_t i = 0; i < (CAP/2)-1; i++){ //+-1?
        word = word << 2;
        word = word | a;
    }
    return word;
}
size_t maskWord(size_t word, int pos){
    if((pos<0) || (pos>=CAP)) return 0;
    word = word << 2*(CAP-1);
    word = word >> 2*pos;
    return word;
}
size_t* Rna::getChain() {
    return chain;
}
int Rna::getCount() {
    return count;
}
int Rna::getLen(){
    if(count%CAP == 0) return count/CAP;
    return (count/CAP)+1;
}

Rna::Rna(Nucl a, int size) {
    size_t f;
    size_t word = 0;
    size_t divRem;
    size_t divN;

    word = createWord(a);
    f = word;
    divRem = size % CAP;
    divN = size / CAP;
    if(divRem != 0){
        chain = new size_t[(divN)+1]();
        f = f << 2*(CAP - (divRem)); //
        chain[divN] = f;
    } else chain = new size_t[divN]();
    for(int i = 0; i<divN; i++) chain[i] = word;
    count = size;
}

bool Rna::isComp(Rna* compTo) {
    int a = compTo->getCount();
    size_t* b = compTo->getChain();
    if (a != count) return false;
    printf("%d", b[1] ^ chain[1] );
    if (count%CAP != 0){
        a = count-1;
        if((b[a] ^ chain[a]) != (createWord(3) << 2*(CAP - (count%CAP)) ) ) return false; //last not full check
    }
    for (int i = 0; i<a; i++){
        if((b[i] ^ chain[i]) != createWord(3)) return false; //all check
    }
    return true;
}

//size_t Rna::pop(int pos) {
//    return chain[pos];
//}

Rna Rna::operator+(Rna& r){
    int newCount = count+r.getCount();
    size_t* newChain = new size_t[newCount]();
    memcpy(newChain, chain, getLen());
    for(int i = 0; i<r.getCount(); i++){
        newChain[getLen()] = newChain[getLen()] | maskWord(r.getChain()[i%CAP], count%CAP);
        count++;
    }
    return *this;
}

bool Rna::operator==(Rna &r) {
    if(r.getCount() != count) return false;
    size_t* compare = r.getChain();
    int len = getLen();
    for(int i = 0; i<len; i++){
        if(chain[i] != compare[i]) return false;
    }
    return true;
}

//Rna Rna::operator=(Rna &r) { //??
//    count = r.getCount();
//    chain = r.getChain();
//    return *this;
//}