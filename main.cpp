// test check in

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <random>
#include <cstring>
#include <cctype>

//#include "firstnames.txt"
//#include "lastnames.txt"
using namespace std;

// Used for learning how to initialize hash tables
// https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus
void initializehash(){
  cout << "Placeholder of initalizing the hash table" << endl;
}

void rehash(){
  cout << "Placeholder of rehashing when too many collisions" << endl;
}

void genstd(){
    int numgenstd;
    srand(time(NULL));
    int id = 400000;
    
    cout << "How many students do you want to generate? :";
    cin >> numgenstd;
    
    numgenstd = int(numgenstd-1);
    for(int i=0;i<=numgenstd;i++){

      string myText;
      ifstream MyReadFirst("firstnames.txt");
      ifstream MyReadLast("lastnames.txt");

      //https://www.w3schools.com/cpp/cpp_vectors.asp
      vector<string> fname = {""};
      vector<string> lname = {""};
    
      bool generate = true;
      while(generate){
        while(getline(MyReadFirst, myText)){
          fname.push_back(myText);
        }
        while(getline(MyReadLast, myText)){
          lname.push_back(myText);
        }

        //https://www.w3schools.com/cpp/cpp_howto_random_number.asp
        int num = rand() % 41;
    
        cout << fname[num] << " ";
        cout << lname[num] << ", ";

        MyReadFirst.close();
        MyReadLast.close();
      
        generate = false;
      }

      int gpa;
      cout << rand() % 4 << "." << rand() % 10 << rand() % 10 << rand() % 10 << ", ";

      cout << int(id+i) << endl;
    }
}

void addstd(){
  string stdname;
  float stdgpa;
  int stdid;
  
  cout << "What is your student's name?: ";
  cin >> stdname;

  cout << "What is your student's GPA?: ";
  cin >> stdgpa;

  cout << "What is your student's ID?: ";
  cin >> stdid;
}

void prtstd(){
  cout << "Printing Student" << endl;
}

void delstd(){
  cout << "Deleting Student" << endl;
}

void commandcheck(){
  string command;
  bool cmdcheck = true;
  while (cmdcheck){
    cout << "What command would you like to do? (help for commands): ";
    cin >> command;
    for(auto& x : command){
      x = tolower(x);
    }

    
    if (command == "help"){
      cout << "Commands: " << endl;
      cout << "--------" << endl;
      cout << "  Add   " << endl;
      cout << " Remove " << endl;
      cout << " Print  " << endl;
      cout << "Generate" << endl;
      cout << "--------" << endl;
      
    }

    else if (command == "add"){
      cout << "----------------\n" << endl;
      addstd();
      cout << "\n----------------" << endl;
    }
      
    else if (command == "remove"){
      cout << "remove" << endl;
    }
      
    else if (command == "print"){
      cout << "print" << endl;
    }

    else if (command == "generate"){
      cout << "\n----------------\n" << endl;
      genstd();
      cout << "\n----------------" << endl;
    }

    else{
      cout << "Invalid command, try again." << endl;
    }
  }  
}

int main(){

  commandcheck();
  

  return 0;

}

