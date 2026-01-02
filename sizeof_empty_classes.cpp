

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

int main()
{
    cout << sizeof(B) << endl; // 1 byte
    cout << sizeof(C) << endl; // 1 byte
    cout << sizeof(D) << endl; // 1 byte (isnt 2 bytes ??!!)
    return 0;
}
