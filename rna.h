#ifndef rna_h
#define rna_h
#endif

enum Nucl{A, G, C, T};
//00 -- 11 A--T
//01 -- 10 G--C

class Rna{
private:
    size_t* chain;
    int count;
public:
    int getLen();
    Rna(Nucl a, int size);
    size_t* getChain();
    //size_t pop(int pos);
    int getCount();
    bool isComp(Rna* compTo);
    Rna operator+(Rna& r);
    bool operator==(Rna& r);
    Rna operator=(Rna& r);

//    bool operator!=(Rna& r);
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
