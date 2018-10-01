 /**
     *  Course: CMPS 2143 - OOP
     *
     *  Purpose: Overload operators 
     * 
     *  @author Shania Roberts 
     *  @version 1.1 01/10/18
     *  @github repo: https://github.com/Shaniamoro/2143-OOP-Roberts
     */
#include <iostream>
#include "myVector.h"

using namespace std;


int main() {
myVector v1(10);
myVector v2(10);

v1.pushBack(8);
// v1 contains: [8]
cout<<"v1 contains:"<< v1 <<endl; 

v2.pushBack(10);
v2.pushBack(20);
v2.pushBack(30);
// v2 contains: [10,20,30]
cout<<"v2 contains:"<< v2 <<endl; 

// Declare some int array
int A[] = {1,2,3,4,5};

v1.pushBack(A,5);
// v1 contains: [8,1,2,3,4,5]
cout<<"v1 contains:"<< v1 <<endl; 

v1 = v1 + v2;
cout<<"v1 contains:"<< v1 <<endl; 
// v1 contains: [18,21,32,3,4,5]

//cout<<v1<<endl;
// would print: [18,21,32,3,4,5] to standard out.

cout<<"The third item in v1 is: " <<v1[2]<<endl;
// would print: 32 to standard out.

// myVector v3(10);
// v3.pushBack(3);
// v3.pushBack(3);
// v3.pushBack(3);

v2 = v2 * 3;
// v2 contains: [30,60,90]
cout<<"v2 contains:"<< v2 <<endl; 

v2 = v2 * v1;
// v2 contains: [540,1260,2880]
cout<<"v2 contains:"<< v2 <<endl; 

v2[2] = 100;
// v2 contains: [540,1260,100]
cout<<"v2 contains:"<< v2 <<endl; 


  // cout << "Checking if if [] is overloaded" <<endl;
  // cout<<"Looking at the 3rd position "<<v2[2]<<endl;
  // cout<<"Looking at the 4th position "<<v1[3]<<endl; 
  // cout<<"Checking if << is overloaded"<<endl;
  // cout <<v1 <<endl;
  // cout<<"Checking if + is overloaded"<<endl;
  // myVector v3 = v1+v2;
  // cout<< v3 <<endl;
  // cout<<"Checking if - is overloaded"<<endl;
  // myVector v4= v1-v2;
  // cout << v4 <<endl;
  // cout<<"Checking if * is overloaded"<<endl;
  // myVector v5= v1*v2;
  // cout << v5 <<endl;
  // cout<<"Checking if / is overloaded"<<endl;
  // myVector v6= v1/v2;
  // cout << v6 <<endl;
  // cout<<"Checking if == is overloaded"<<endl;
  // cout <<(v1==v2) <<endl;
  // cout<<"Checking if = is overloaded"<<endl;
  // cout <<(vx=vy) <<endl;

  
}