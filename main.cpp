#include <iostream>
#include <cstdlib>
#include <ctime>

// 1. OOP Grunder - look for NOUNS
// ShoppingCart
// Product
// Customer
// ShoppingCart cart;
// cart.add(product);
// 2. structs vs classes vs objects
/// CLASS = ritning (blueprint)
// instansiera/bygga en SAK från en ritning
//     => objekt

// 3. Stefans OOP Dinner
//          there are humans in Stefans house
//          humans have
//                       - level (0 initially)
//                       - name
//          humans can
//                       - act (either eat, drink or burp)
//                       - level up (if you burp three times in a row, you level up)
// 4. Encapsulation
// 5. In vector...

// 6. INHERITANCE arv
//         new 
//         there are also ... FLIES in Stefans house


class Human {
    std::string name;
    int level;
    int age;
public:
    Human(std::string name,int age) {
        this->name = name;
        this->age = age;
        this->level = 1;
        std::cout << "Human created!" << std::endl;
    }

      void act(){
        std::string actions[]={"eats","drinks","burps"};
        int index = rand()% 3; 
         std::cout << name << " " << actions[index] << std::endl;
      }

};

int main() {
    srand((unsigned) time(NULL));
    Human stefan("Stefan", 30);
    Human kerstin("Kerstin", 28);
    Human oliver("Oliver", 5);

    while(true) {
        stefan.act();
        kerstin.act();
        oliver.act();

        
        std::cout << "Press key for next turn " << std::endl;
        std::cin.get();
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}