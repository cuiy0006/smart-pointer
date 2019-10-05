#include "smart_pointer.h"

class SomeClass: public RefBase{
public:
    SomeClass(){
        std::cout << "Call SomeClass Constructor" << std::endl;
    }
    virtual ~SomeClass(){
        std::cout << "Call SomeClass Destructor" << std::endl;
    }
};


void testcase(){
    SomeClass *p = new SomeClass;
    SmartPointer<SomeClass> sp1 = p; //copy
    std::cout << "ref cnt: " << p->getRefCount() << std::endl;
    {
        SmartPointer<SomeClass> sp2 = sp1; //copy
        std::cout << "ref cnt: " << p->getRefCount() << std::endl;
    }
    std::cout << "ref cnt: " << p->getRefCount() << std::endl;

    SmartPointer<SomeClass> sp3 = new SomeClass;
    sp1 = sp3; // assign
    std::cout << "ref cnt: " << p->getRefCount() << std::endl;
}


int main(){
    testcase();
    return 0;
}