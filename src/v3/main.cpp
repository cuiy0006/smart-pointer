#include "smart_pointer.h"

class SomeClass: public RefBase{
public:
    SomeClass(){
        std::cout << "Call SomeClass Constructor" << std::endl;
    }
    virtual ~SomeClass(){
        std::cout << "Call SomeClass Destructor" << std::endl;
    }

    void foo(){
        std::cout << "Call SomeClass foo" << std::endl;
    }
};

class OtherClass: public RefBase{
public:
    OtherClass(){
        std::cout << "Call OtherClass Constructor" << std::endl;
    }
    virtual ~OtherClass(){
        std::cout << "Call OtherClass Destructor" << std::endl;
    }

    void bar(){
        std::cout << "Call OtherClass bar" << std::endl;
    }
};


void testcase1(){
    std::cout << "================TESTCASE1 START==============" << std::endl;
    SmartPointer<SomeClass> sp1 = new SomeClass;
    (*sp1).foo();
    sp1->foo();
    std::cout << "================TESTCASE1 END==============" << std::endl;
}

void testcase2(){
    std::cout << "================TESTCASE2 START==============" << std::endl;
    SmartPointer<SomeClass> sp1 = new SomeClass;
    SomeClass* p1 = new SomeClass;
    SmartPointer<SomeClass> sp3;
    SmartPointer<SomeClass> sp4 = p1;
    SmartPointer<SomeClass> sp5 = sp1;

    if(sp3 == NULL && sp1 != NULL){
        std::cout << "isNULL test passed" << std::endl;
    }

    if(sp1 != sp4 && sp1 == sp5){
        std::cout << "compare SmartPointers test passed" << std::endl;
    }

    if(sp1 != p1 && sp4 == p1){
        std::cout << "compare SmartPointer and raw pointer test passed" << std::endl;
    }

    std::cout << "================TESTCASE2 END==============" << std::endl;
}

int main(){
    testcase1();
    testcase2();
    return 0;
}