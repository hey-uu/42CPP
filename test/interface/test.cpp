#include <iostream>
#include <string>

class Abase {
public:
  Abase(std::string const &name);
  Abase &operator=(Abase const &other);
  ~Abase(void);
  virtual void show(void) const = 0;

protected:
  std::string _type;
};

class Derived1 : public Abase {
public:
  Derived1(std::string const &name);
  Derived1 &operator=(Derived1 const &other);
  ~Derived1(void);
  virtual void show(void) const;
};

class Derived2 : public Abase {
public:
  Derived2(std::string const &name);
  Derived2 &operator=(Derived2 const &other);
  ~Derived2(void);
  virtual void show(void) const;
};

Abase::Abase(std::string const &name) : _type(name) {
  std::cout << "ABASE string constructor" << std::endl;
}
Abase &Abase::operator=(Abase const &other) {
  std::cout << "ABASE operator=" << std::endl;
  if (this != &other)
  _type = other._type;
  return (*this);
}
Abase::~Abase(void) { std::cout << "ABASE  destructor" << std::endl; }

Derived1::Derived1(std::string const &name) : Abase(name) {
  std::cout << "DERIVED1 string constructor" << std::endl;
}
Derived1 &Derived1::operator=(Derived1 const &other) {
  std::cout << "DERIVED1 operator=" << std::endl;
  this->_type = other._type;
  return (*this);
}
Derived1::~Derived1(void) { std::cout << "DERIVED1 destructor" << std::endl; }

void Derived1::show(void) const {
  std::cout << "DERIVED1 : " << _type << std::endl;
}

Derived2::Derived2(std::string const &name) : Abase(name) {
  std::cout << "DERIVED2 string constructor" << std::endl;
}
Derived2 &Derived2::operator=(Derived2 const &other) {
  std::cout << "DERIVED2 operator=" << std::endl;
  this->_type = other._type;

  return (*this);
}
Derived2::~Derived2(void) { std::cout << "DERIVED2 destructor" << std::endl; }

void Derived2::show(void) const {
  std::cout << "DERIVED2 : " << _type << std::endl;
}

int main(void)
{
  Derived1  d1("first");
  Derived2  d2("second");

  std::cout << "==========" << std::endl;
  Abase &base_ref = d1;
  std::cout << "==========" << std::endl;
  base_ref.show();
  std::cout << "==========" << std::endl;
  base_ref = d2;
  std::cout << "==========" << std::endl;
  base_ref.show();
  std::cout << "==========" << std::endl;
  return (0);
}
