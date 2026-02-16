/*
Dylan Waters
2/15/26

Name : Hash Table

Description : Start from your Student List program or Linked List part 2, meaning you need ADD, PRINT, DELETE, and QUIT. Change the way the students are stored; use a hash table. 
You should create a hash function using the student data which attempts to spread out data evenly through the table. It can be something you make up, or you may use a pre-existing hash formula. 
The hash table should start with at least 100 slots (of an array, not a vector).  It should be able to deal with collisions in a valid way. We will be using chaining, which means each entry is actually a linked list. (10 points) 
If you get more than 3 collisions when you are chaining (so you add, or would add, a fourth node to a single chain), create a table to have at least double the number of slots, then rehash your students into the new table.  
(Your hash should alter based on the size of the table, by the way, and it should spread out the data as you resize the table.  Make it so.)  (10 points)

In addition to adding students manually to the hash table, create a random student generator.  You should have a file with a list of first names and a file with a list of last names.  
Your student list program should be able to randomly generate new students by grabbing a random student first and last name from the corresponding files, incrementing the id number, adding a random GPA (much like real life), and adding it in.  
Make sure you have a command that allows you to specify how many students to generate and add.  This will make debugging your project MUCH easier.  (10 points)

Comment. (5 points)

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

#include "hashtable.h"

using namespace std;

int TABLE_SIZE = 100; // The hash table should start with at least 100 slots

// Generate a random amount of students and add them to the hash table
void genstd(HashTable& table){
    uint32_t numgenstd;
    srand(time(NULL));
    uint32_t id = 400000;
    
    cout << "How many students do you want to generate? :";
    cin >> numgenstd;
    
    string myText;
    ifstream MyReadFirst("firstnames.txt"); // Read file with first names
    ifstream MyReadLast("lastnames.txt"); // Read file with last names

    // Initialize vectors empty (no blank string)
    vector<string> fname;
    vector<string> lname;
  
    // Read first and last names
    while(getline(MyReadFirst, myText)){
      fname.push_back(myText);
    }
    while(getline(MyReadLast, myText)){
      lname.push_back(myText);
    }

    MyReadFirst.close();
    MyReadLast.close();

    // Choose random student name (first or last depending on file)
    for(uint32_t i = 0; i < numgenstd; i++){
      int num = rand() % fname.size();
      int num2 = rand() % lname.size();

      Student* student = new Student;
      student->name = fname[num] + " " + lname[num2];
      student->gpa = rand() % 400 / 100.0f; // Generate a GPA between 0.0 and 4.0
      student->id = id + i;
      student->next = nullptr; // Initialize next pointer to nullptr
      table.add(student);
    }
}

// Add a student to the database by asking for their first name, last name, and GPA
void addstd(HashTable& table){
    string stdfirstname;
    string stdlastname;
    float stdgpa;
    uint32_t stdid;
    
    cout << "What is your student's first name?: ";
    cin >> stdfirstname;
    
    cout << "What is your student's last name?: ";
    cin >> stdlastname;

    cout << "What is your student's GPA?: ";
    cin >> stdgpa;

    Student* student = new Student;
    student->name = stdfirstname + " " + stdlastname;
    student->gpa = stdgpa;
    student->id = stdid;
    student->next = nullptr; // Initialize next pointer to nullptr
    table.add(student);

    cout << "Student added with ID: " << student->id << endl;
}

// Print all students in the hash table
void prtstd(HashTable& table){
    table.print();
}

// Delete a student from the hash table from ID number
void delstd(HashTable& table){
    uint32_t id;
    cout << "Enter the ID of the student to delete: ";
    cin >> id;
    table.remove(id);
}

// Print out the commands for the user
void printcmds(){
    cout << "Commands: " << endl;
    cout << "----------------" << endl;
    cout << "Add - Add student entry into database" << endl;
    cout << "Remove - Remove student entry from database" << endl;
    cout << "Print - Print all students in database" << endl;
    cout << "Generate - Generate random students and add them to database" << endl;
    cout << "Exit - Exit the program" << endl;
    cout << "----------------" << endl;
}

// Main function to run the program
int main(){

    HashTable table(TABLE_SIZE);

    // Print out commands for user
    printcmds();

    string command;
    bool cmdcheck = true;

    while (cmdcheck){

        cout << "What command would you like to do? (help for commands): ";
        cin >> command;
        for(auto& x : command){
          x = tolower(x); // No matter upper case or lower case it will work
        }

        if (command == "help"){
          cout << "----------------" << endl;
          printcmds();
          cout << "----------------" << endl;
        }
        else if (command == "add"){
          cout << "----------------" << endl;
          addstd(table);
          cout << "----------------" << endl;
        }
        else if (command == "remove"){
          cout << "----------------" << endl;
          delstd(table);
          cout << "----------------" << endl;
        }
        else if (command == "print"){
          cout << "----------------" << endl;
          prtstd(table);
          cout << "----------------" << endl;
        }
        else if (command == "generate"){
          cout << "----------------" << endl;
          genstd(table);
          cout << "----------------" << endl;
        }
        else if (command == "exit"){
          cout << "----------------" << endl;
          cout << "Exiting program..." << endl;
          cmdcheck = false;
        }
        else{
          cout << "Invalid command, try again." << endl;
        }
    }

    return 0;
}

