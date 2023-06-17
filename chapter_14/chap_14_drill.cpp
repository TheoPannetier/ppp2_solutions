/*
 1. Define a class B1 with a virtual function vf() and a non-virtual function f(). Define both of these functions within class B1. Implement each function to output its name (e.g., B1::vf()). Make the functions public. Make a B1 object and call each function.
 2. Derive a class D1 from B1 and override vf(). Make a D1 object and call vf() and f() for it.
 3. Define a reference to B1 (a B1&) and initialize that to the D1 object you just defined. Call vf() and f() for that reference.
 4. Now define a function called f() for D1 and repeat 1–3. Explain the results.
 
    - when b1_ref.vf() is called, B1 looks for def of vf() in D1 since it is virtual; but not for f(), where only the def in B1 is used. b1_ref refers to a D1 object, which member vf() overrides B1::vf(). There is no overriding for B1::f(), so when called from a B1 object (d1_ref is a B1 object) uses this def.
    - above it, d1 is a D1 object so d1.f() uses the def for this class.
 
 5. Add a pure virtual function called pvf() to B1 and try to repeat 1–4. Explain the result.
    - cannot because that makes B1 an abstract class, calls to it via b1 error.
 
 6. Define a class D2 derived from D1 and override pvf() in D2. Make an object of class D2 and invoke f(), vf(), and pvf() for it.
 7. Define a class B2 with a pure virtual function pvf(). Define a class D21 with a string data member and a member function that overrides pvf(); D21::pvf() should output the value of the string.
 Define a class D22 that is just like D21 except that its data member is an int. Define a function f() that takes a B2& argument and calls pvf() for its argument. Call f() with a D21 and a D22.
*/

#include "std_lib_facilities.h"

class B1 {
public:
    void f() {
        cout << "B1::f()\n";
    }
    virtual void vf() {
        cout << "B1::vf()\n";
    }
    virtual void pvf() = 0;
};

class D1 : public B1 {
    public:
    void vf() {
        cout << "D1::vf()\n";
    }
    void f() {
        cout << "D1::f()\n";
    }
};

class D2 : public D1 {
    public:
    void pvf() {
        cout << "D2::pvf()\n";
    }
};

class B2 {
    public:
    virtual void pvf() = 0;
};

class D21 : public B2 {
public:
    void pvf() { cout << m_str << '\n'; }
private:
    string m_str{"hello"};
};

class D22 : public B2 {
public:
    void pvf() { cout << m_i << '\n'; }
private:
    int m_i{36};
};

void f(B2& arg)
{
    arg.pvf();
}

int main()
{
    try {
        D2 d2;
        d2.f();
        d2.vf();
        d2.pvf();
        
        D21 d21;
        D22 d22;
        f(d21);
        f(d22);
        
        // return 0;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        return 2;
    }
}
