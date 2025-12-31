#include <iostream>
#include <iomanip>
using namespace std;
class point{
  public:
  int m_x,m_y;
  point(int x,int y){
    m_x = x;
    m_y = y;
  }
  enum flags {
  pos=1,
  scient=2,
  base=4
  };
};
// cout << "hello world" << endl;
ostream& operator<<(ostream &out,point p){
    out << p.m_x << " " << p.m_y;
    return out;
}
istream& operator>>(istream &in,point p){
    in >> p.m_x >> p.m_y;
    return in;
}



int main()
{
    point::flags t = point::pos;
    cout << ios::showbase << endl;
    (t&(1<<0))? cout<<"yes"<<endl:cout<<"no"<<endl;
    ios::fmtflags f = cout.flags();
    cout << f << endl;
    point p(3,10);
    cout << p << endl;
    //cin >> p;
    cout << p << endl; // p will not change as we passed p by value, if we pass it by ref it will change
   // ostream out;
    //out << "hello world ";
    //out << "amir jribi\n";
    //cout << out << endl;
    cout<<setprecision(8)<<fixed;
    cout<<(double)12.5566778899<<endl;
    cout<<(double)12.5566778899<<endl;
    cout<<(double)12.556<<endl;
     cout<<12.0<<endl;
    return 0;
}
