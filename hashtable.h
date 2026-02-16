/*
Dylan Waters
2/15/26

Description: Define a hash table class to store student records.
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

using namespace std;

struct Student{
  std::string name;
  float gpa;
  int id;
  Student* next;
};

class HashTable {
public:
    HashTable(int initialSize);
    ~HashTable();
    
    void add(Student* student);
    void remove(int studentId);
    void resize();
    void print();
    
private:
    int size;
    Student** table;
    
    int hash(int studentId);

    int studentIdCounter; // Counter to assign unique IDs to students
};

#endif // HASHTABLE_H
