/*
Dylan Waters
2/15/26

Description: Implement a hash table to store student records, using chaining to handle collisions.

*/

#include "hashtable.h"
#include <iostream>
#include <cassert>


// Constructor to initialize the hash table with a given initial size
HashTable::HashTable(int initialSize) {
    studentIdCounter = 0; // Initialize student ID counter

    if (initialSize <= 0){
        initialSize = 100; // default initial size
    }
    size = initialSize;
    table = new Student*[size];
    for (int i = 0; i < size; ++i){
        table[i] = nullptr;
    }
}

// Destructor to clean up memory used by the hash table
HashTable::~HashTable() {
    // Delete all chained Student nodes and then the table array
    for (int i = 0; i < size; ++i) {
        Student* cur = table[i];
        while (cur) {
            Student* next = cur->next;
            delete cur;
            cur = next;
        }
    }
    delete[] table;
}

// Hash function to compute the index for a given student ID
int HashTable::hash(int studentId) {
    if (size <= 0){
        return 0;
    }
    int h = studentId % size;
    if (h < 0){
        h += size;
    }
    return h;
}

// Add a student to the hash table, resizing if necessary to maintain performance
void HashTable::add(Student* student){
    // assign new unique ID to student. Overwrite any existing ID in the student object, since we will use this ID for hashing and lookups
    student->id = 400000 + studentIdCounter;
    studentIdCounter++;

    if (!student){
        return;
    }
    // Count collisions at target index
    int idx = hash(student->id);
    int count = 0;
    for (Student* cur = table[idx]; cur; cur = cur->next) {
        ++count;
    }

    if (count >= 3) {
        // Rehash into table double the size
        resize();
        // recompute index after resize
        idx = hash(student->id);
    }

    // Insert at head of chain
    student->next = table[idx];
    table[idx] = student;
}

// Remove a student from the hash table by their ID
void HashTable::remove(int studentId) {
    int idx = hash(studentId);
    Student* cur = table[idx];
    Student* prev = nullptr;
    while (cur) {
        if (cur->id == studentId) {
            if (prev) {
                prev->next = cur->next;
            } else {
                table[idx] = cur->next;
            }
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    // nothing to do
}

// Resize the hash table when the number of collisions at an index exceeds a threshold
void HashTable::resize() {

    cout << "Resizing hash table from size " << size << " to size " << (size * 2) << endl;
    int newSize = size * 2;

    Student** newTable = new Student*[newSize];
    for (int i = 0; i < newSize; ++i){
        newTable[i] = nullptr;
    }

    // Move nodes into new table (rehash)
    for (int i = 0; i < size; ++i) {
        Student* cur = table[i];
        while (cur) {
            Student* next = cur->next; // save next pointer before we change it
            int newIdx = cur->id % newSize;
            if (newIdx < 0) newIdx += newSize;
            // insert at head in new table
            cur->next = newTable[newIdx];
            newTable[newIdx] = cur;
            cur = next;
        }
    }

    delete[] table;
    table = newTable;
    size = newSize;
}

// Print all students in the hash table, along with total count and maximum chain length.
void HashTable::print() {
    int totalStudents = 0;
    int maxChainLength = 0;
    
    for (int i = 0; i < size; ++i) {
        Student* cur = table[i];
        int chainLength = 0;
        while (cur) {
            cout << "ID: " << cur->id << ", Name: " << cur->name << ", GPA: " << cur->gpa << endl;
            totalStudents++;
            cur = cur->next;
            chainLength++;
        }
        if (chainLength > maxChainLength) {
            maxChainLength = chainLength;
        }
    }

    cout << "Total number of students: " << totalStudents << endl;
    cout << "Hash table size: " << size << endl;
    cout << "Maximum chain length: " << maxChainLength << endl;
}