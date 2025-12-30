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
};
class d:public b{
    int m_z;
    public:
    // didnt call base class constructor : def cons will be called
    d(int z){
        cout<<"parm constructor of d + def base class cons"<<endl;
        m_z = z;
    }
    d(int z, int x, int y):b(x,y){
        cout<<"parm constructor of d + param base class cons"<<endl;
        m_z = z;
    }
};

int main()
{
    d dd(5,6,7);
  //parm cons of b
  //parm constructor of d + param base class cons
    return 0;
}
