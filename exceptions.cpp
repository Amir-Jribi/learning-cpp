#include <iostream>
using namespace std;
class A{
  public:
  void hello(){
      cout << "hello world" << endl;
  }
};
class B{
  public:
  void hello(){
      cout << "hello world" << endl;
  }
};
class C: public B{
    
};
class D:public B,public A{
    
};
void handle_all(int i){
    try {
        if (i>=0){
            throw i;
        }
        else {
            throw 'a';
        }
    }
    catch(...){ 
        cout << "catched all exeptions !!" << endl;
    }
}
void handle(int i) throw (int,char,double){ // throwing multiple exepctions
    if (i>=0){
            throw i;
    }
    else {
        throw 'a';
    }
}
// still to include rethrowing an expection inside catch block
int main()
{
    handle_all(10);handle_all(-10);
    try{
        handle(-10);
    }
    catch(int j){
         cout << "catched integer exeption" << endl;
    }
    catch(char j){
         cout << "catched char exeption" << endl;
    }
    C c;
    B b;
    try {
        throw c;
    }
    catch (B b) {
        cout << "catch base class" << endl;
    }
    catch(C c){// warning: exception of type ‘C’ will be caught by earlier handler
        cout << "catch derived class" << endl;
    }
    
    try {
        throw c;
    }
    catch(C c){
        cout << "catch derived class" << endl;
    }
    catch (B b) {
        cout << "catch base class" << endl;
    }
    //throw 10; throw not inside try-catch block terminate called after throwing an instance of 'int'
     
    
    

    return 0;
}
