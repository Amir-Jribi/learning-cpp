#include <iostream>
using std::cout;
using std::endl;
void fun(const int& lval)
{
    cout << "lval refrence to const" << endl;
}
void fun(int&& rval)
{
    cout << "rvalue refrence" << endl;
}
/*
https://www.learncpp.com/cpp-tutorial/rvalue-references/
Non-const l-value references can only bind to non-const l-values.
Const l-value references can bind to non-const l-values, const l-values, and r-values.
R-value references can only bind to r-values.
*/
int main()
{
    int p = 20;
    int&& rrval = 20;
    fun(p); // lval refrence to const
    fun(rrval); // lval refrence to const  (Rvalue reference variables are lvalues)
    fun(5); // rvalue refrence
    // int& ref2{ 5 }; // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    int&& ref4 = 20;
    ref4 = p;
    int&& ref5 = p;
    /*
    const int x = 10;
    const int* y = &x;
    int* z = const_cast<int*>(y);
    *z = 20; // undefined behaviour
    // modifying the const object through a reference or pointer to non-const type
    // results in undefined behavior.
    */
    /*
    const int& e = 10;
    int* d = &e;
    // error: invalid conversion from ‘const int*’ to ‘int*’
    */
    /*
    int&& r = 20;
    int e = 10;
    r = e; // e will be bounded to an rval
    e++;
    cout << r << " " << e << endl;
    */
    /*
    const int& a = 5; // const lval refrence initialized with rval : works
    */
    /*
    int c = 10;
    const int& b = c; // const lval refrence initialized with non const lval : works
    c++;
    cout << b << " " << c << endl; // 11 11
    */
    
    /*
    int& x = 5; // non const lval refrence initialized with rval : invalid
    error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    */
    /*
    const int y = 6;
    int& z = y;
    // error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers
    */
    return 0;
}
