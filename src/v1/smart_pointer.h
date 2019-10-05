#ifndef SMART_POINTER
#define SMART_POINTER

#include <iostream>

template <typename T>
class SmartPointer{
public:
    SmartPointer(): mPointer(NULL){
        std::cout << "created NULL pointer at " << static_cast<const void*>(mPointer) << std::endl;
    }
    SmartPointer(T* p): mPointer(p){
        std::cout << "created pointer at " << static_cast<const void*>(mPointer) << std::endl;
    }
    ~SmartPointer(){
        std::cout << "delete pointer at " << static_cast<const void*>(mPointer) << std::endl;
        if(mPointer){
            delete mPointer;
        }
    }
private:
    T* mPointer;
};

#endif