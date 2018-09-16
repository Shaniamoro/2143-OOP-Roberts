#include <iostream>
#include "myVector.h"
//#include <iomanip>  

using namespace std;

int main() {
  myVector V;
  string temp;
 
 // Create instance of myvector of size 10 and immediately
 // attempt to pop_back (remove from empty vector).
 // Removing from an empty vector should return false.
  cout << "Attempting to remove from empty vector"<< endl;
  V.pop_back(); 
  // Nothing to print
  //V.print();
  cout <<endl;

  //Insert the values 13,31,73 into your vector. Print it out.
  cout << "Attempting to add 13,37,73 to our vector and printing it: "<< endl;
  V.push_back(13);
  V.push_back(37);
  V.push_back(73);
  V.print();
  cout << endl; 
  cout << endl; 

  //Insert 10000 items into your vector. Print the size of your vector.
  cout<< "Adding 1000 items into vector and printing size"<<endl; 

  // Random number generator 
  for(int i=0;i<1000;i++){
    V.push_back(rand()%1000);
  };
  cout << "There are " << V.size() << " items in the vector." << endl;
  cout << "The size of the vector is: " << V.vCapacity() << endl;
  cout << endl; 

  //Remove 998 items from your vector. Print the size of your vector.
  cout << "Deleting 998 items from the vector and printing size"<< endl; 
  for(int i=0;i<998;i++){
     V.pop_back();
   }
  cout << "There are " << V.size() << " items in the vector." << endl;
  cout << "The size of the vector is: " << V.vCapacity() << endl;
   cout << endl;

  //Print out your vector.
  cout << "Printing the elements in the Vector:" << endl;
  V.print();
  cout << endl; 
  
  
}