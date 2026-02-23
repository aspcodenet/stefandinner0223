#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <vector>

// 1. OOP Grunder - look for NOUNS
// ShoppingCart
// Product
// Customer
// ShoppingCart cart;
// cart.add(product);
// 2. structs vs classes vs objects
/// CLASS = ritning (blueprint)
// instantiate/building a THING 
//     => objekt

// 3. Stefans OOP Dinner
//          there are humans in Stefans house
//          humans have
//                       - level (1 initially)
//                       - name
//          humans can
//                       - act (either eat, drink or burp)
//                       - level up (if you burp three times in a row, you level up)

// 4. In vector...

// 5. INHERITANCE arv
//         new 
//         there are also ... FLIES in Stefans house

// Inheritance = code reuse and DRY (Don't Repeat Yourself)
// Dog = give birth to living things + breastfeed, BARK, eat, sleep, ...
// Cat = give birth to living things + breastfeed, MEOW, eat, sleep, ...
// Mammal = give birth to living things + breastfeed, eat, sleep, ...

// Dog - IS A - Mammal and it has a BARK method
// Cat - IS A - Mammal and it has a MEOW method 

class GameCharacter { // base class
//private 
protected: // accessible in derived classes   
    std::string name;
public: // accessmodifier 
    GameCharacter(std::string name) {
        this->name = name;
        std::cout << "GameCharacter created!" << std::endl;
    }
    void act() {
        std::cout << name << " does something." << std::endl;
    }

    void mightLevelUp() {
        // Base GameCharacter doesn't level up, so this function does nothing
    }

};

//     semantic meaning is that a human IS A game character, and a fly IS A game character
class Human : public GameCharacter { // derived class
    int level;
    int age;
    int burpCount = 0; // count consecutive burps
public:
    Human(std::string name,int age) : GameCharacter(name) {
        this->age = age;
        this->level = 1;
        std::cout << "Human created!" << std::endl;
    }


    void mightLevelUp() {
        if(burpCount >= 3) {
            level++; // level = level + 1
            burpCount = 0; // reset burp count after leveling up
            std::cout << name << " leveled up to level " << level << "!" << std::endl;
        }
    }

      void act(){// function / method
        std::string actions[]={"eats","drinks","burps"};
        int index = rand()% 3; 
        if( actions[index] == "burps") {
            burpCount++;
        } else {
            burpCount = 0; // reset burp count if action is not a burp
        }
         std::cout << name << " " << actions[index] << std::endl;
      }

};

class Fly : public GameCharacter {
public:
    Fly(std::string name) : GameCharacter(name) {
        std::cout << "Fly created!" << std::endl;
    }

    void act() {
        std::string actions[]={"flies","lands in the food", "buzzes"};
        int index = rand()%3;
        std::cout << "Fly " << name << " " << actions[index] << std::endl;
    }

    void mightLevelUp() {
        // Flies don't level up, so this function does nothing
    }


};




int main() {
    srand((unsigned) time(NULL));

//    std::shared_ptr<Human> h = std::make_shared<Human>("Stefan", 30);

    Human stefan("Stefan", 30);
    Human kerstin("Kerstin", 28);
    Human oliver("Oliver", 5); // human is a gamecharacter
    Fly fly("Buzz"); // fly is a gamecharacter
    std::vector<GameCharacter> humans; // resizable array


    humans.push_back(stefan);
    humans.push_back(kerstin);
    humans.push_back(oliver);
    humans.push_back(fly); // add a new human to the vector

    while(true) { // gameloop
        //  A COPY of each human in humans will be created and stored in human
        // REFERENCES ARE aliases, they point to the same object in memory
        for(GameCharacter &human : humans) { // for each human in humans
            human.act();
        }
       // humans.push_back(Human("New Human", 20)); // add a new human to the vector
        for(GameCharacter &human : humans) { // for each human in humans
            human.mightLevelUp();
        }
        
        std::cout << "Press key for next turn " << std::endl;
        std::cin.get();
    }
    return 0;
}