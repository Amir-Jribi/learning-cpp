#include <iostream>

int main()
{
    int a = 20;
    int b = 10;
    int const* p1 = &a; // int* const, vs const int *
    a = 30;
    p1 = &b; //valid
    // *p1 = 40; // invalid
     int * const p2 = &a; // const pointer
     // p2 = &b; // non valid
     *p2 = 50;
     const int* p3 = &a; // pointer to const 
     p3 = &b; // valid
    // *p3 = 50; error: assignment of read-only location ‘* p3’
    
    std::cout<<(*p1) << std::endl;
    std::cout<<"Hello World";

    return 0;
}
