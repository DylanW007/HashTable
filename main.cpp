#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <random>
#include <cstring>
//#include "firstnames.txt"
//#include "lastnames.txt"
using namespace std;

void genstd(){
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
    srand(time(0));
    int num = rand() % 41;
    
    cout << fname[num] << "\n";
    cout << lname[num] << endl;
    generate = false;
  }
}

void prtstd(){
  cout << "Printing Student" << endl;
}

void addstd(){
  cout << "Adding Student" << endl;
}

void delstd(){
  cout << "Deleting Student" << endl;
}

int main(){

  genstd();

}

