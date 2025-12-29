#include <bits/stdc++.h>
using namespace std;
class point{
    public:
    int m_x,m_y;
    point() = default; // i'm happy with the initilization that the compiler will do it for me (which is junk values !)
    point(int x,int y):m_x(x),m_y(y){
        cout<<"paramerized constructor"<<endl;
    }
    point (const point &other){
        cout<<"copy constructor"<<endl;
        m_x = other.m_x;
        m_y = other.m_y;
    }
    point& operator=(const point &other){
        cout<<"assignment constructor"<<endl;
        if (this != &other){ // not a self assignment
           m_x = other.m_x;
           m_y = other.m_y; 
        }
        return *this; // create a chain of assignments
    }
    /*
    // error: ‘bool operator()(const point&, const point&)’ must be a member function
    function call operator must be a member function , since we need an object to use this operator
    friend bool operator()(const point &p, const point &q) {
        if (p.m_x == q.m_x) {
            return p.m_y < q.m_y;
        }
        return p.m_x < q.m_x;
    }
    */
    ~point(){
        cout<<"destructor"<<endl;
    }
};
/*
bool cmp(int a,int b) const {  // error: non-member function ‘bool cmp(int, int)’ cannot have cv-qualifier
    return a<b; // cmp should be member function of a class / struct
    //const at the end means: Calling this function does NOT modify the state of the object.
}
*/
struct cmp{
  bool operator()(const point &p, const point &q) const {
        if (p.m_x == q.m_x) {
            return p.m_y < q.m_y;
        }
        return p.m_x < q.m_x;
  }
};
bool compare (const point &p, const point &q) {
        if (p.m_x == q.m_x) {
            return p.m_y < q.m_y;
        }
        return p.m_x < q.m_x;
}
int main()
{
    // point p(); compiler will think that p is a function that returns point object , 
    //point p is how we call def constructor
    point q;
    cout<<q.m_x<<" "<<q.m_y<<endl; // junk values
    point p(5,8);
    cout<<p.m_x<<" "<<p.m_y<<endl;
    std::vector<point> v{p,q} ;
    sort(v.begin(),v.end(),compare);
    cmp cp;
    sort(v.begin(),v.end(),cp);
    sort(v.begin(),v.end(),cmp()); // we need a callable object , cmp is just a type !!
    //cout<<p()<<endl;
    // Function names decay to function pointers
    return 0;
}
