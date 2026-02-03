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

/* Not using just yet
void action(){
  cout << "Generate\nAdd\nPrint\nDelete." << endl;
  cout << "What action do you want to do?: ";
  cin >> action;
}*/

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

int main(){

  genstd();
  return 0;

}

