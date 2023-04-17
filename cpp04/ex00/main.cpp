#include <iomanip>
#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
  /** TEST1 **/
  std::cout << std::endl
            << "======================== TEST1 ========================="
            << std::endl
            << std::endl;
  const Animal *meta = new Animal();
  const Dog *dog1 = new Dog();
  const Animal *dog2 = new Dog();
  const Cat *cat1 = new Cat();
  const Animal *cat2 = new Cat();

  std::cout << std::endl << "== getType() ==" << std::endl;
  std::cout << "expected = Dog"
            << " => "
            << "real = " << dog1->getType() << std::endl;
  std::cout << "expected = Dog"
            << " => "
            << "real = " << dog2->getType() << std::endl;
  std::cout << "expected = Cat"
            << " => "
            << "real = " << cat1->getType() << std::endl;
  std::cout << "expected = Cat"
            << " => "
            << "real = " << cat2->getType() << std::endl;
  std::cout << std::endl;

  std::cout << std::endl << "== makeSound() ==" << std::endl;
  meta->makeSound();
  dog1->makeSound();
  dog2->makeSound();
  cat1->makeSound();
  cat2->makeSound();
  std::cout << std::endl;

  delete meta;
  delete dog1;
  delete dog2;
  delete cat1;
  delete cat2;

  /** TEST2 **/
  std::cout << std::endl
            << "======================== TEST2 ========================="
            << std::endl
            << std::endl;
  const WrongAnimal *wrong_meta = new WrongAnimal();
  const WrongCat *wrong_cat1 = new WrongCat();
  const WrongAnimal *wrong_cat2 = new WrongCat();

  std::cout << std::endl << "== getType() ==" << std::endl;
  std::cout << "expected = WrongCat"
            << " => "
            << "real = " << wrong_cat1->getType() << std::endl;
  std::cout << "expected = WrongCat"
            << " => "
            << "real = " << wrong_cat2->getType() << std::endl;
  std::cout << std::endl;

  std::cout << std::endl << "== makeSound() ==" << std::endl;
  wrong_meta->makeSound();
  wrong_cat1->makeSound();
  wrong_cat2->makeSound();
  std::cout << std::endl;

  delete wrong_meta;
  delete wrong_cat1;
  delete wrong_cat2;

  /** TEST3 **/
  std::cout << std::endl
            << "======================== TEST3 ========================="
            << std::endl
            << std::endl;
  const Animal &ref_meta = Animal();
  const Dog &ref_dog1 = Dog();
  const Animal &ref_dog2 = Dog();
  const Cat &ref_cat1 = Cat();
  const Animal &ref_cat2 = Cat();

  std::cout << std::endl << "== getType() ==" << std::endl;
  std::cout << "expected = Dog"
            << " => "
            << "real = " << ref_dog1.getType() << " " << std::endl;
  std::cout << "expected = Dog"
            << " => "
            << "real = " << ref_dog2.getType() << " " << std::endl;
  std::cout << "expected = Cat"
            << " => "
            << "real = " << ref_cat1.getType() << " " << std::endl;
  std::cout << "expected = Cat"
            << " => "
            << "real = " << ref_cat2.getType() << " " << std::endl;
  std::cout << std::endl;

  std::cout << std::endl << "== makeSound() ==" << std::endl;
  ref_meta.makeSound();
  ref_dog1.makeSound();
  ref_dog2.makeSound();
  ref_cat1.makeSound();
  ref_cat2.makeSound();
  std::cout << std::endl;

  /** TEST4 **/
  std::cout << std::endl
            << "======================== TEST4 ========================="
            << std::endl
            << std::endl;

  const WrongAnimal ref_wrong_meta = WrongAnimal();
  const WrongCat ref_wrong_cat1 = WrongCat();
  const WrongAnimal ref_wrong_cat2 = WrongCat();

  std::cout << std::endl << "== getType() ==" << std::endl;
  std::cout << "expected = WrongCat"
            << " => "
            << "real = " << ref_wrong_cat1.getType() << " " << std::endl;
  std::cout << "expected = WrongCat"
            << " => "
            << "real = " << ref_wrong_cat2.getType() << " " << std::endl;
  std::cout << std::endl;

  std::cout << std::endl << "== makeSound() ==" << std::endl;
  ref_wrong_meta.makeSound();
  ref_wrong_cat1.makeSound();
  ref_wrong_cat2.makeSound();
  std::cout << std::endl;

  return (0);
}