/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
    ~b(){
        cout<<"destructing b"<<endl;
    }
};
// private inheritance :
// public and protected members in base class become private members 
// of the derived class
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
    ~d(){
        cout<<"destructing d"<<endl;
    }
};

class e:public d{
    public:
    e(){
        cout<<"def const of e"<<endl;
    }
    ~e(){
        cout<<"destructing e"<<endl;
    }
};
class F{
    public:
    F(){
        cout<<"def const of F"<<endl;
    }
    ~F(){
        cout<<"destructing F"<<endl;
    }
};
class G{
    public:
    G(){
        cout<<"def const of G"<<endl;
    }
    ~G(){
        cout<<"destructing G"<<endl;
    }
};
class C:public F,public G{
    public:
    C(){
        cout<<"def const of C"<<endl;
    }
    ~C(){
        cout<<"destructing C"<<endl;
    }
};
/*
Constructors are called
in order of derivation; destructors are called in reverse order. When a class inherits more than one base 
class at a time, constructors are called in order from left to right as specified in the derived class’ 
inheritance list. Destructors are called in reverse order right to left. 
*/
int main()
{
    e ee;
    /*
    def cons of b
    def const of d
    def const of e
    destructing e
    destructing d
    destructing b
    */
    C cc;
    /*
    def const of F
    def const of G
    def const of C
    destructing C
    destructing G
    destructing F
    */
    return 0;
}
