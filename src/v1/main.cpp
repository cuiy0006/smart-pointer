#include "smart_pointer.h"
#include <iostream>

class SomeClass {
    public:
        SomeClass(){
            std::cout << "init some class" << std::endl;
        }
};

void testCase(){
    SmartPointer<char> p1;
    SmartPointer<char> p2 = NULL;
    SmartPointer<SomeClass> p3(new SomeClass);
    SmartPointer<const char> p4 = "Hello World!";
}

int main(void){
    testCase();
    return 0;
}

// create pointer:
// created NULL pointer at 0x0
// created created pointer at 0x0
// init some class
// created pointer at 0x7f8d38402b40
// created pointer at 0x102921f10

// detele pointer:
// delete pointer at 0x102921f10
// sptestcase1(75469,0x10f4f25c0) malloc: *** error for object 0x102921f10: pointer being freed was not allocated
// sptestcase1(75469,0x10f4f25c0) malloc: *** set a breakpoint in malloc_error_break to debug