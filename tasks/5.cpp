class Character{
public:
    void walk(){
        doStep(); 
    }
    virtual void plan(){};
};
class Villian : public Character {
public:
    void walk(){
        doEvilStep(); 
    }
    void plan(){
        //doEvil(); 
    }
};
Character c;
Villian v;
Character* cPtr;
cPtr = &c;
cPtr->doEvil; //реализация из Caracter
cPtr->doStep; //реализация из Caracter
cPtr = &v;
cPtr->doEvil; //реализация из Villian
cPtr->doStep; //реализация из Caracter
