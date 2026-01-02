#include <iostream>
using namespace std;
int main()
{
    try{
        int x,y;
        cin>>x>>y;
        if (y == 0){
            throw 0; // there isnt here conversion from int to double
        }
        cout << x/y << endl;
    }
    catch (double y){
        cout << "divison by 0 is prohibited" << endl;
    }
    // program crashes
    // terminate called after throwing an instance of 'int'
    

    return 0;
}
