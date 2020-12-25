class A{
public:
  int i = -1;
  std::string code;
  A(){
  i++;
  }
  void except(){
    code = itoa(i)+generate();
    throw this;
   }
  std::string generate(){};
}
class B : public A{
  B() : A(){
  i++
  }
}
class C : public B{
  C() : B(){
  i++
  }
}
int main(){
try{
someFunc()
} catch(A a){
  if(a->code == ){
  
  }
} 
}
