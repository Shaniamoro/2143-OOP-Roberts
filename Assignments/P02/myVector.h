#include <iostream>
using namespace std;

/**
  * Class: myVector
  * Purpose: Implements vector that holds integers. 
  * Methods:
  *     void change_Capacity();
  *     void reduce_Capacity();
  *     double percentFull(); 
  *     void push_back(int);
  *     int size();
  *     int vCapacity();
  *     int operator[](int)
  *     void pop_back();
  *     void print();
  *
  */

class myVector{

private:
  // Pointer to the array
  int *vArray;
  //actual size of the vector; how much memory we allocate 
  //if vSize> capacity we have to allocate new memory
  int vSize, capacity,min_capacity;
  // To allocate new memory  
  void change_Capacity();
  // deallocate memory
   void reduce_Capacity();
  // Checks the percentage of the container used 
  double percentFull();  
  
public:
  myVector();
  myVector(int);
  //deconstructor: deallocate memory 
  ~myVector(); 
  //push an element to the end of the array
  void push_back(int);
   //return the size of the vector 
  int size();
  // reurns the capacity of the vector 
  int vCapacity();
  //The element we want to return
  int operator[](int);
  //Removes value at the end of our array 
  void pop_back();
  //prints our vector 
  void print();
  
 
 
};