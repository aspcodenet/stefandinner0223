#include <iostream>
#include <cstring>
#include <memory>

// Dynamically allocated memory = heap memory
// reallocating memory = resizing the heap memory
// in vector, string etc = things that can GROW and SHRINK dynamically, they manage their own memory and they use the heap to store their data

// lets implement a simple list class that manages its own memory
// useless - template

// lets implemenet a simple string class that manages its own memory

// RAII = Resource Acquisition Is Initialization
// 1. Constructor = acquire resource (allocate memory)
// 2. Destructor = release resource (deallocate memory)

// Pointers - lets implement shared_ptr and unique_ptr

class MyList {
    // pointer is just an address, 1000
    int* m_data; // a pointer to an int, a pointer to an array of ints
    int count;

public:
    MyList(){
        m_data = nullptr; // m_data = NULL;
        count = 0;        
    }

    void print() {
        for (int i = 0; i < count; i++) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }


    ~MyList() {
        delete[] m_data;
    }
    void add(int value) {
        int* newData = new int[count + 1]; // create an array [] of size count + 1
        // copy old data to new data
        for (int i = 0; i < count; i++) {
            newData[i] = m_data[i];
        }
        // add new value to new data
        newData[count] = value;
        delete[] m_data;
        m_data = newData;
        count++;
    }
};  


class SimpleString {
private:
    char* m_buffer;
    int m_size;
public:
    SimpleString(const char* str = "") {
        m_size = std::strlen(str);
        m_buffer = new char[m_size + 1]; // +1 for null terminator
        std::strcpy(m_buffer, str);
    }

    ~SimpleString() {
        delete[] m_buffer;
    }


    SimpleString operator+(const char* str) const {
        size_t newSize = m_size + std::strlen(str);
        char* newBuffer = new char[newSize + 1];
        std::memcpy(newBuffer, m_buffer, m_size);
        std::memcpy(newBuffer + m_size, str, std::strlen(str) + 1);
        SimpleString result(newBuffer);
        delete[] newBuffer; // Clean up temporary buffer
        return result;      
    }

    friend std::ostream& operator<<(std::ostream& os, const SimpleString& str) {
        os << str.m_buffer;
        return os;
    }

};

class Player{
public:
    int jersey;
    std::string name;
};

class Insurance{
public:
    std::string company;
    double coverageAmount;
};

template<typename T>
class SmartPointer{
    T* ptr;
public:

    SmartPointer() {
        ptr = new T();
    }

    ~SmartPointer() {
        delete ptr;
    }
    T* operator->() {
        return ptr;
    }
};

void test(const Player &player){
    std::cout << "Player name: " << player.name << ", Jersey: " << player.jersey << std::endl;
}

int main() {
    int x = 12;
    if(x > 10) {
        Player player1;
        player1.jersey = 10;
        player1.name = "Messi";
        test(player1); // pass by reference, changes to player in the function affect player1 in main

        // 17:20

        // unique_ptr - a smart pointer that owns a resource exclusively, it cannot be copied, only moved, when the unique_ptr goes out of scope, it automatically deletes the resource it owns
        std::unique_ptr<Player> stefan = std::make_unique<Player>();
        stefan->name = "Stefan";
        stefan->jersey = 30;
        
        // is a "pointer"/reference as you know it from C#/Java
    //    std::shared_ptr<Player> sharedPlayer = std::make_shared<Player>();
    //    std::shared_ptr<Player> sharedPlayer2 = sharedPlayer; // shared ownership, reference counting, when the last shared_ptr that owns the resource goes out of scope, it automatically deletes the resource, we can have multiple shared_ptrs pointing to the same resource
        // "garbage collector"
        SmartPointer<Insurance> insuranceSmart;
        SmartPointer<Player> playerSmart; // dynamically allocated memory, we have to manage it ourselves, we have to delete it when we're done with it
    
        playerSmart->jersey = 7;
        playerSmart->name = "Ronaldo";
        //delete p2; // WHATS THE PROBLEM??
    } // player1 goes out of scope, its destructor is called, but p2 is still in memory, we have a memory leak
    int r = 12;



    int x =12;
    if(x == 12){
        SimpleString str2("Hello, World!");
    }
    int i = 0;
    // RAII - Resource Acquisition Is Initialization
    // memory allocations, sockets, datbaase connections, file handles, mutex locks, etc
    SimpleString str("Hello, World!");

    str = str + " How are you?";

    std::cout << str << std::endl;





    // std::list
    // std::vector<int> vec;
    // std::vector<Player> players;
    MyList list;
    list.add(1);
    list.add(2);
    list.add(21);
    //
    list.print();

    // RAII - allocating in constructor, deallocating in destructor


    // // in embedded systems, we often have to manage our own memory, 
    // // we don't have the luxury of a garbage collector or smart pointers, we have to be careful with memory leaks and dangling pointers
    // char* buffer = new char[4]; // Initial allocation for "Cat" + null terminator
    // std::strcpy(buffer, "Cat");

    // std::cout << "Old address: " << (void*)buffer << " Content: " << buffer << std::endl;

    // // 2. We want to grow it to hold "Catastrophic"
    // const char* extension = "astrophic";
    // size_t newSize = std::strlen(buffer) + std::strlen(extension);

    // // 3. MANUAL GROWTH
    // char* newBuffer = new char[newSize + 1]; // New allocation
    // std::strcpy(newBuffer, buffer);          // Copy old data
    // std::strcat(newBuffer, extension);       // Append new data

    // delete[] buffer;                         // Free old memory (CRITICAL)
    // buffer = newBuffer;                      // Update the pointer

    // std::cout << "New address: " << (void*)buffer << " Content: " << buffer << std::endl;

    // delete[] buffer; // Final cleanup
    return 0;
}