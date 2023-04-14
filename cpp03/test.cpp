#include <iostream>

class A {
public:
  virtual void func(void) { std::cout << "A\n"; };

private:
  int num;
};

class B : virtual public A {
public:
  using A::func;
  virtual void func(void) { std::cout << "B\n"; }
};

class C : virtual public A {
public:
  using A::func;
  virtual void func(void) { std::cout << "C\n"; }
};

class D : public B, public C {
  using A::func;
  using B::func; // 컴파일 에러
  using C::func;
};

