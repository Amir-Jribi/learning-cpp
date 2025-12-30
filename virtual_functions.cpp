#include <bits/stdc++.h>
using namespace std;

class b{
    // private members cannot be accessed directly outside the class
    int m_x,m_y;
    public:
    b(){
        m_x = m_y = 0;
        cout<<"def cons of b"<<endl;
    }
    b(int x,int y){
        cout<<"parm cons of b"<<endl;
        m_x = x;
        m_y = y;
    }
    void setX(int x){
        m_x = x;
    }
    void setY(int y){
        m_y = y;
    }
    virtual void show(){
        cout<<"show in base class"<<endl;
    }
    ~b(){
        cout<<"destructing b"<<endl;
    }
};
class d:public b{
    int m_z;
    public:
    // didnt call base class constructor : def cons will be called
    d(){
        cout<<"def const of d"<<endl;
        m_z = 0;
    }
    d(int z){
        cout<<"parm constructor of d + def base class cons"<<endl;
        m_z = z;
    }
    d(int z, int x, int y):b(x,y){
        cout<<"parm constructor of d + param base class cons"<<endl;
        m_z = z;
    }
    void show(){
        cout<<"show in derived class"<<endl;
    }
    ~d(){
        cout<<"destructing d"<<endl;
    }
};

int main()
{
    d derived,*dd;
    b base,*bb;
    bb= &derived;
    cout<<sizeof(derived)<<endl; // 12 bytes
    cout<<sizeof(*bb)<<endl; // 8 bytes
    //bb->show(); // without virtual , it will invoke show in the b class as it doesnt have access to show in d class
    bb->show(); // without virtual , it will invoke show in the d class !!
    b &bd = derived;
    bd.show(); // without virtual , it will invoke show in the d class !!
    /*
    bb->show(); // error: ‘class b’ has no member named ‘show’
    dd = &base; // error: invalid conversion from ‘b*’ to ‘d*’
    */
    /*
    b &bd = derived; // can access only to the members inside the base class!
    cout<<bd.show()<<endl; // error: ‘class b’ has no member named ‘show’
    */
    return 0;
}
