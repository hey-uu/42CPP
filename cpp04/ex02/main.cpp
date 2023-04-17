#include <iomanip>
#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <sstream>

#include <cstdlib>

void check_leaks(void) { system("leaks Animal"); }

int main(void) {
  std::stringstream ss;
  std::string str;

  /** TEST1 **/
  std::cout << std::endl
            << "======================== TEST1 ========================="
            << std::endl
            << std::endl;

  Animal *animal_arr[10];
  Animal *animal_arr_copy[10];
  Dog *dog_arr_copy[5];
  Cat *cat_arr_copy[5];

  // construction
  std::cout << "== construction ==" << std::endl;
  for (int i = 0; i < 5; i++) {
    std::cout << i + 1 << "th : " << std::endl;
    ss << i;
    str = ss.str();
    animal_arr[i] = new Dog("test1_dog_" + str + "_");
    ss.str("");
  }
  for (int i = 5; i < 10; i++) {
    std::cout << i + 1 << "th : " << std::endl;
    ss << i;
    str = ss.str();
    animal_arr[i] = new Cat("test1_cat_" + str + "_");
    ss.str("");
  }
  std::cout << std::endl;

  // show informations
  std::cout << "== Show Me the Brain! ==" << std::endl;
  for (int i = 0; i < 5; i++) {
    std::cout << i + 1 << "th : " << std::endl;
    static_cast<Dog *>(animal_arr[i])->showBrainUpTo(i + 1);
  }
  for (int i = 5; i < 10; i++) {
    std::cout << i + 1 << "th : " << std::endl;
    static_cast<Cat *>(animal_arr[i])->showBrainUpTo(i + 1);
  }
  std::cout << std::endl;

  std::cout << "== Make Some Noise!! ==" << std::endl;
  for (int i = 0; i < 10; i++) {
    animal_arr[i]->makeSound();
  }
  std::cout << std::endl;

  // copy
  std::cout << "== copy animals ==" << std::endl;
  for (int i = 0; i < 10; i++)
    animal_arr_copy[i] = animal_arr[i]->clone();
  std::cout << std::endl;
  std::cout << "== Show Me the Brain! ==" << std::endl;
  for (int i = 0; i < 5; i++) {
    std::cout << i + 1 << "th : " << std::endl;
    static_cast<Dog *>(animal_arr_copy[i])->showBrainUpTo(i + 1);
  }
  for (int i = 5; i < 10; i++) {
    std::cout << i + 1 << "th : " << std::endl;
    static_cast<Cat *>(animal_arr_copy[i])->showBrainUpTo(i + 1);
  }
  std::cout << "== Make Some Noise!! ==" << std::endl;
  for (int i = 0; i < 10; i++)
    animal_arr_copy[i]->makeSound();
  std::cout << std::endl;

  std::cout << "== copy dogs ==" << std::endl;
  for (int i = 0; i < 5; i++)
    dog_arr_copy[i] = new Dog(*dynamic_cast<Dog *>(animal_arr[i]));
  std::cout << std::endl;

  std::cout << "== copy cats ==" << std::endl;
  for (int i = 0; i < 5; i++)
    cat_arr_copy[i] = new Cat(*dynamic_cast<Cat *>(animal_arr[5 + i]));
  std::cout << std::endl;

  // destruction
  std::cout << "== destruction ==" << std::endl;
  std::cout << "===== delete animal_arr =====" << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << i + 1 << "th : " << std::endl;
    delete animal_arr[i];
  }
  std::cout << std::endl;
  std::cout << "===== delete animal_arr_copy =====" << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << i + 1 << "th : " << std::endl;
    delete animal_arr_copy[i];
  }
  std::cout << std::endl;

  std::cout << "===== delete dog_arr_copy =====" << std::endl;
  for (int i = 0; i < 5; i++) {
    std::cout << i + 1 << "th : " << std::endl;
    delete dog_arr_copy[i];
  }
  std::cout << std::endl;

  std::cout << "===== delete cat_arr_copy =====" << std::endl;
  for (int i = 0; i < 5; i++) {
    std::cout << i + 1 << "th : " << std::endl;
    delete cat_arr_copy[i];
  }
  std::cout << std::endl;
  /** TEST2 **/
  std::cout << std::endl
            << "======================== TEST2 ========================="
            << std::endl
            << std::endl;

  Cat cat1("THISISCAT_");
  Cat cat_copy1(cat1);
  Cat cat_copy2 = cat1;

  std::cout << "before copy: " << std::endl;
  cat1.showBrainUpTo(2);
  std::cout << "after copy using copy constructor: " << std::endl;
  cat_copy1.showBrainUpTo(2);
  std::cout << "after copy using assignment operator:" << std::endl;
  cat_copy2.showBrainUpTo(2);
  // atexit(check_leaks);
  return (0);
}
