/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Hello{
    public:
    Hello(){
        cout<<"const"<<endl;
    }
    ~Hello(){
        cout<<"dest"<<endl;
    }
};
/*
When an object goes out of scope normally, or a dynamically allocated object 
is explicitly deleted using the delete keyword, the class destructor is automatically
called (if it exists) to do any necessary clean up before the object is removed from memory. 
For simple classes (those that just initialize the values of normal member variables), 
a destructor is not needed because C++ will automatically clean up the memory for you.
https://www.learncpp.com/cpp-tutorial/destructors/
*/
int main()
{
    Hello* h = new Hello;
    delete h;
    Hello hh = Hello();
    return 0;
}
