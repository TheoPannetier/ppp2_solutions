/*
 For each exercise, create and test (with output) a couple of objects of the defined classes to demonstrate that your design and implementation actually do what you think they do. Where exceptions are involved, this can require careful thought about where errors can occur.
 9. Re-implement vector::operator=() (§19.2.5) using an allocator (§19.3.7) for memory management.
 
 Key:
 
 template<typename T> class allocator {
 public:
    // . . .
    T* allocate(int n);                 // allocate space for n objects of type T
    void deallocate(T* p, int n);       // deallocate n objects of type T starting at p
    void construct(T* p, const T& v);   // construct a T with the value v in p
    void destroy(T* p);                 // destroy the T in p
 };
*/

#include <exception>
#include <cmath>
#include <iostream>
#include <memory>
//#include <stdlib.h>
//using namespace std; // redefine vector2
#include "std_lib_facilities.h"


class vector2
{
public:
    vector2(): sz{0}, elem{nullptr}, space{0} {}
    explicit vector2(const int& s): sz{s}, elem{new double[s]}, space{s} {
        for(int i = 0; i < s; ++i) elem[i] = 0.0;
    }
    int size() const { return sz; }
    
    double& operator[](const int& n) { return elem[n]; } // access operator, ref
    const double& operator[](const int& n) const { return elem[n]; } // access operator, val
    
    vector2& operator=(const vector2& a); // copy assignment
    
    ~vector2() { delete[] elem; }

private:
    int sz;
    double* elem;
    int space;
    allocator<double> alloc;
};

vector2& vector2::operator=(const vector2& a)
 // like copy constructor, but we must deal with old elements
{
    // allocate new space
    double* p = alloc.allocate(a.size());
    // copy in new space
    // alloc.construct(p, a); construct won't work because of :)))))) standard shenanigans
    for(int i = 0; i < a.size(); ++i) p[i] = a[i];
    // free previous elements
    alloc.destroy(elem);
    // update size and space
    sz = space = a.size();
    // update pointer
    elem = p;
    return *this; // return self-reference
}

/*
 double* p = new double[a.sz]; // allocate new space
 for (int i = 0; i < a.sz; ++i) p[i] = a.elem[i]; // copy elements
 delete[] elem; // deallocate old space
 space = sz = a.sz; // set new size
 elem = p; // set new elements
 return *this; // return self-reference
*/

std::ostream& operator<<(std::ostream& os, const vector2& vec)
{
    for (int i = 0; i < vec.size(); ++i)
        os << vec[i] << ' ';
    return os;
}

int main()
{
    try {
        vector2 v1(3);
        for (int i = 0; i < v1.size(); ++i)
            v1[i] = 1 + 2*i;
        
        vector2 v2(3);
        
        v2 = v1; // case same length
        std::cout << v1 << '\n' << v2 << std::endl;
        v2 = vector2(2);
        v2 = v1; // case v2 shorter
        std::cout << v1 << '\n' << v2 << std::endl;
        v2 = vector2(4);
        v2 = v1; // case v2 longer
        std::cout << v1 << '\n' << v2 << std::endl;
        v2 = vector2();
        v2 = v1; // case v2 empty
        std::cout << v1 << '\n' << v2 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "exception\n";
        return 2;
    }
}
