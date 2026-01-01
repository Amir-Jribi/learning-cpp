#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ostream& change(ostream& out){
    out << setprecision(2) << fixed; // use iomanip
    return out;
}
int main()
{
    ofstream out; // use fstream
    out.open("file.txt",ios::out); // to open a file you need to linked to a ofstream
    if (!out){
        cout<<"cannot open file.txt";
        return 0;
    }
    out << "hello world" << endl;
    out << "amir jribi" << endl;
    out.close();
    const char *p = "hello there  \n";
    ofstream fout;
    fout.open("test.txt",ios::out | ios::binary);
    while(*p){
        fout.put(*p);
        p++;
    }
    double d = 5.66778899;
    cout<<d<<endl; // 5.667788
    change(cout); // same as cout << change;
    cout<<d<<endl; // 5.66
    
    return 0;
}
