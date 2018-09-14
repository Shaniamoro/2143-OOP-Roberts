/**
    *  Course: CMPS 3013 - Algorithms
    *  Assignment: P02
    *  Purpose: Array Vector Class
    * 
    *  @author Shania Roberts 
    *  @version 1.1 09/14/18
    */

#include <iostream>
#include "myVector.h"
using namespace std;

 /**
  * constructor that initializes the list when it
  * is empty and first being declared.
  *
  * @param {None}
  * @return {NULL}
  */
myVector::myVector(){
  min_capacity=10;
  capacity = 10;
  vArray = new int[capacity];
  vSize = 0;
 // cout << "Initial Capacity is " << capacity << endl;
}

  /**
  * Constructor that initializes the vector 
  *
  * @param {int} size: the size allocated for the vector
  * @return {NULL}
  */ 
myVector::myVector(int size){
  capacity = size;
  vArray = new int[capacity];
  vSize = 0;
}

 /**
  * Deconstructor to deallocate memory and avoid leaks 
  *
  * @param {None}
  * @return {NULL} 
  */
myVector::~myVector(){
  delete[] vArray;
}
 /**
  * Checks the percentage of the allocated memory that was used
  *
  * @param {None}
  * @return {double} percent: returns the value of the percentage found
  */
double myVector::percentFull(){
  double size = vSize ;
  double capacity1 = capacity;
  double percent = (size/capacity);
  return percent;
}
 /**
  * Pushes an element to the end of the array
  *
  * @param {int} i: the index that we're searching ofr 
  * @return {NULL}
  */
void myVector::push_back(int i){
  // Checks if the allocated memory is sufficient
  if (vSize+1>capacity){
    change_Capacity();
  }
  vArray[vSize]=i;
  vSize++;  
  }


 /**
  * Removes an item from the end of the array
  *
  * @param {None}
  * @return {NULL}
  */
void myVector::pop_back(){
  if (vSize != 0){
    vSize--;  
    reduce_Capacity();
  } else 
  cout<<"false";
  return;
  
}
 /**
  * Implementation of [] operator.  
  * This function returns an int value as if the list were an array.
  *
  * @param {int} i: the index of the node we're searching for 
  * @return {object} i: returns the value of the Node at the index given
  */
int myVector::operator[] (int i){
  return vArray[i];
}

 /**
  * Returns the size of the vector 
  *
  * @param {None}
  * @return {int} vSize: the number of items in the vector 
  */
 int myVector::size(){
    return vSize;
  }
  /**
  * Returns the size of the memory allocated for the vector
  *
  * @param {None}
  * @return {int} capacity: allocated memory for the vector
  */  
 int myVector::vCapacity(){
   return capacity;
 }

 /**
  * When the vector is full it is made to be 1.5 times its size 
  *
  * @param {None} 
  * @return {NULL}
  */
void myVector:: change_Capacity(){
  // Make the allocated memory twice its size
  capacity = vSize* 1.5;
  //cout << "Capacity changed!" << endl;
  //cout << "New Capacity is " << capacity << endl;
  //Make a new array
  int* temp = new int [capacity];
  //Copy the elements into new array
  for(int i=0;i<vSize;i++)
    temp[i]=vArray[i];
  //Delete allocated space for array 
  delete[] vArray;
  vArray=temp;
}
 /**
  * When pop_back is used and the vectore is 40% full its 
  * allocated memory is cut in half
  *
  * @param {None} 
  * @return {NULL}
  */
void myVector:: reduce_Capacity(){
  //cout<< percentFull();
  //cout<< capacity<< " Cap";
    if (percentFull() >= .40 && percentFull() <.41 ){
      if (capacity > (min_capacity*2)){
        // Make the allocated memory half its size
        capacity = capacity/2 ;
        //cout << "Capacity changed!" << endl;
        //cout << "New Capacity is " << capacity << endl;
        //Make a new array
        int* temp = new int [capacity];
        //Copy the elements into new array
        for(int i=0;i<vSize;i++)
         temp[i]=vArray[i];
        //Delete allocated space for array 
        delete[] vArray;
       vArray=temp;
      } 
    } 
}
/**
  * Prints the content of the Vector
  * @param {None} 
  * @return {NULL}
  */
void myVector::print(){
  for(int i=0;i<vSize;i++){
    cout<<vArray[i]<<" ";
  }
}

