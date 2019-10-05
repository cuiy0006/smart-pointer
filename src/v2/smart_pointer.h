#ifndef SMART_POINTER
#define SMART_POINTER

#include <iostream>

template <typename T>
class SmartPointer{
public:
    SmartPointer(T* p): mPointer(p){
        if(mPointer){
            mPointer->incRefCount();
        }
    }
    SmartPointer(const SmartPointer& other): mPointer(other.mPointer){
        if(mPointer){
            mPointer->incRefCount();
        }
    }

    SmartPointer &operator = (const SmartPointer& other){
        if(other.mPointer){
            other.mPointer->incRefCount();
        }
        
        if(mPointer && mPointer->decRefCount() == 0){
            delete mPointer;
        }
        mPointer = other.mPointer;
        return *this;
    }

    ~SmartPointer(){
        if(mPointer && mPointer->decRefCount() == 0){
            delete mPointer;
        }
    }
private:
    T* mPointer;
};

class RefBase {
public:
    RefBase(): mCount(0){
    }

    void incRefCount(){
        ++mCount;
    }

    int decRefCount(){
        return --mCount;
    }

    int getRefCount(){
        return mCount;
    }

    virtual ~RefBase(){}

private:
    int mCount;
};

#endif