/*
Dylan Waters
2/15/26

Description: Define a hash table class to store student records.
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <cstdint>

using namespace std;

struct Student{
    std::string name;
    float gpa;
    uint32_t id;
    Student* next;
};

class HashTable {
public:
    HashTable(uint32_t initialSize);
    ~HashTable();
    
    void add(Student* student);
    void remove(uint32_t studentId);
    void resize();
    void print();
    
private:
    int size;
    Student** table;
    
    uint32_t hash(uint32_t studentId);

    uint32_t studentIdCounter; // Counter to assign unique IDs to students
};

#endif // HASHTABLE_H
