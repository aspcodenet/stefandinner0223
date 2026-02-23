#include <iostream>
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
        int index = rand()%3;   
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