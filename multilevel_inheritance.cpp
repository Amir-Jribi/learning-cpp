#include <bits/stdc++.h>
using namespace std;

class b{
    // private members cannot be accessed directly outside the class
    int m_x,m_y;
    public:
    b(){
        m_x = m_y = 0;
        cout<<"default constructor of b"<<endl;
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
    protected:
    int m_f;
};
// private inheritance :
// public and protected members in base class become private members 
// of the derived class
class d:private b{
    int m_z;
    public:
    // didnt call base class constructor : def cons will be called
    d(){
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
};
// public inheritance:
// public members in base class become public members of the derived class
// protected members in base class become protected members of the derived class 
class e:public d{
    void where(){
        cout<<m_f<<endl; 
    }
};

// protected inheritance:
// When a base class is inherited by use of protected, 
//its public and protected members become protected members of
//the derived class.
int main()
{
    d dd(5,6,7);
    e ee;
// cannot access it since m_f is private in d
        // error: ‘int b::m_f’ is private within this context

    return 0;
}
