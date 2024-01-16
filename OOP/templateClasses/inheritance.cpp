class Base {
public:
  virtual void foo() = 0; // pure virtual func
  virtual void foo2();    // non-pure virtual func
  void bar() = {return 42;
}; // regular func
}

// base(aka superclass or parent) class: the class that gets inherited from
// Derived(aka subclass or child) class: the class that inherits from the base
// class

// always calls the superclass constructor
// if not specified. calls the default constructor of base

class Derived : public Base {
  Derived() : Base(args), {
    //
  }
};

// if you intend to make your class inheritable(i.e
// if your class has any virtual funcs), make your destructor virtual

// virtual ~Base(){}
// otherwise will almost definitely have memory leaks;
/* whether or not the destructor is virtual is a good indication of
whether a class is intended to be inherited from. */

class Base {
  ~Base() {}
};
class Derived : public Base {
  ~Derived() {}
};
Base *b = new Derived();
delete b; // never calls the destructor for derived!

// access specifiers
/*private: can only be accessed by this class
protected: can only be accessed by this class or derived classes
public: can be accessed by anyone
*/

/*
prefer templates when:
1.runtime efficiency is most important
2.no common base can be defined

prefer derived classes when:
1.compile-time efficiency is most important
2.want to hide implementations
3.dont want code bloat
*/

int a = (int)b;
int a = int(b);
int a = static_cast<int>(b); // is considered best practice