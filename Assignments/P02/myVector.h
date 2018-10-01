#include <iostream>

using namespace std;

class myVector{
private:
  int *vPtr;      // int pointer to array
  int maxSize;    // max size of array
  int minSize;    // min size of array
  int index;      // current location to insert or remove
  int* _resize(int);
  
public:
  myVector(int size);
  void pushBack(int item);
  //void pushBack(int *,int size);
  int popBack();
  double percentFull();
  int* resize(double);
  int* resize(int);
  void print();
  int size();
  void size(int);
  int vSize();

/**
  * Implementation of [] operator.  
  * This function returns an int value as if the list were an array.
  *
  * @param {int} i: the index of the node we're searching for 
  * @return {object} i: returns the value of the Node at the index given
  */
 int & operator[](int  i) const { 
      if (i >= maxSize) 
      { 
          cout << "Array index out of bound, exiting\n"; 
          exit(0); 
      }else if(i >= index){
          cout << "Warning: vector["<<i<<"] is undefined ...\n";
      }
      return vPtr[i]; 
  }
  /*
  * Implementation of << operator.  
  * Overload << (ostream) so that if your vector were used in a cout statement
  *  it would print the entire vector without a newline.
  *
  * @param {object} ostream,V: and the vector to be printed 
  * @return {object} the printed vector
  */
  
  friend ostream& operator<<(ostream& os, myVector V ) {
     os << "["; 
    for (int i = 0; i < V.size(); ++i) { 
        os << V[i]; 
        if (i != V.size() - 1) 
            os << ", "; 
    } 
    os << "]\n";

   return os;
  }
  
 /**
  * Implementation of + operator.  
  * Overload + (addition) so that if your vector were used inan arithmetic operation,
  *  it would add two vectors together.
  *
  * @param {int} MyVector , vec:: the vectors we are checking 
  * @return {object} the vector of the added values
 */
  myVector operator+(const myVector & vec) {
    int smaller, bigger;
    int size = this->size();
    myVector combinedVec(size + vec.index);

    if (size < vec.index){
      smaller = size;
      bigger = vec.index;
    
    } else {
       smaller = vec.index;
       bigger = size;

    }
      for (int i = 0 ; i < smaller ; i++ ){
       int temp = this->vPtr[i] + vec[i];
       combinedVec.pushBack(temp);
       }
      for ( int i= smaller ; i< bigger; i++ ){
        if (size > vec.index){
             combinedVec.pushBack(this->vPtr[i]);
        }else {
          combinedVec.pushBack(vec[i]);
        }
      
      }
 
    return combinedVec;
  }

  /**
  * Implementation of - operator.  
  * Overload - (substraction) so that if your vector were used in an arithmetic operation,
  * it would subtract two vectors.
  *
  * @param {object} MyVector , vec: the two vectors to be subtracted
  * @return {object} the subtrated vector 
  */
  
  myVector operator-(const myVector & vec2) {
    int smaller, bigger;
    int size = this->size();
   myVector subtVector(size + vec2.index);

    if (size < vec2.index){
      smaller = size;
      bigger = vec2.index;
    
    } else {
       smaller = vec2.index;
       bigger = size;

    }
      for (int i = 0 ; i < smaller ; i++ ){
       int temp = this->vPtr[i] - vec2[i];
       subtVector.pushBack(temp);
       }
      for ( int i= smaller ; i< bigger; i++ ){
        if (size > vec2.index){
             subtVector.pushBack(this->vPtr[i]);
        }else {
          subtVector.pushBack(vec2[i]);
        }
      
      }
 
    return subtVector;
  }

  /**
  * Implementation of * operator.  
  * Overload * (multiplication) so that if your vector were used in an arithmetic
  * operation, it would multiply two vectors.
  *
  * @param {object} MyVector , vec: the two vectors to be multiplied
  * @return {object} the result vector 
  */
  myVector operator *(const myVector & vec2) {
    int smaller, bigger;
    int size = this->size();
    myVector multiplyVector(size + vec2.index);

    if (size < vec2.index){
      smaller = size;
      bigger = vec2.index;
    
    } else {
       smaller = vec2.index;
       bigger = size;

    }
      for (int i = 0 ; i < smaller ; i++ ){
       int temp = this->vPtr[i] * vec2[i];
       multiplyVector.pushBack(temp);
       }
      // for ( int i= smaller ; i< bigger; i++ ){
      //   if (size > vec2.index){
      //        multiplyVector.pushBack(this->vPtr[i]);
      //   }else {
      //     multiplyVector.pushBack(vec2[i]);
      //   }
      
      // }
    return multiplyVector;

  }
   /**
  * Implementation of * operator.  
  * Overload * (multiplication) so that if your vector were used in an arithmetic
  * operation, it would multiply the vector by an integer.
  *
  * @param {int} item: the two things  to be multiplied
  * @return {object} the result vector 
  */
   myVector operator *(const int item) {
    int size = this->size();

      for (int i = 0 ; i < size ; i++ ) {
        this->vPtr[i] = this->vPtr[i] * item;
      }
       myVector newVector (this->size());
       newVector = *(this);
    return newVector;
  }
  
 /**
  * Implementation of / operator.  
  * Overload / (division) so that if your vector were used in an arithmetic operation,
  * it would divide two vectors.
  *
  * @param {object} MyVector , vec2: the two vectors to be divided
  * @return {object} the result vector 
  */
  
  myVector operator/(const myVector & vec2) {
    int smaller, bigger;
    int size = this->size();
    myVector divVector(size + vec2.index);

    if (size < vec2.index){
      smaller = size;
      bigger = vec2.index;
    
    } else {
       smaller = vec2.index;
       bigger = size;

    }
      for (int i = 0 ; i < smaller ; i++ ){
       int temp = this->vPtr[i] / vec2[i];
       divVector.pushBack(temp);
       }
      for ( int i= smaller ; i< bigger; i++ ){
        if (size > vec2.index){
             divVector.pushBack(this->vPtr[i]);
        }else {
          divVector.pushBack(vec2[i]);
        }
      
      }
 
    return divVector;
  };
   /**
  * Implementation of / operator.  
  * Overload / (division) so that if your vector were used in an arithmetic operation,
  * it would divide two vectors.
  *
  * @param {int} item: number were diving by 
  * @return {object} the result vector 
  */
   myVector operator /(const int item) {
    int size = this->size();

      for (int i = 0 ; i < size ; i++ ) {
        this->vPtr[i] = this->vPtr[i] / item;
      }
       myVector newVector (this->size());
       newVector = *(this);
    return newVector;
  }
  
   /**
  * Implementation of == operator.  
  * Overload == (equality) so that if your vector were used in an arithmetic operation,
  *  it would test for equality.
  *
  * @param {object} MyVector, vec2: the two vectors to be checked
  * @return {bool} if they are equal true, if not then false 
  */
  bool operator==(const myVector & vec2) { 
    int smaller, bigger;
    int size = this->size();

    if (size != vec2.index ){
      return false; 
    } else {
       for (int i = 0 ; i < size ; i++ ){
       if (this->vPtr[i] != vec2[i]) {    
         return false; 
       }
      } 
      return true;
    }

  }
   /**
  * Implementation of = operator.  
  * Overload = (assignment) so that you can assign another vector and take on its values.
  *
  * @param {object} MyVector , vec: the object and what it will be assigned
  * @return {object} the result of the assignment 
  */ 
  myVector operator =( const myVector & vec){ 
    int sizeofDeleted = this->size();
    int sizeofNew = vec.index;

    for (int i = 0 ; i < sizeofDeleted ; i++ ){
      this->popBack();
    }
    for (int i = 0 ; i < sizeofNew ; i++ ){
      this->pushBack(vec[i]);
    }

    return *(this);
  }


  /**
  * Implementation of push_back. 
  * Overlad push_back to accept an array of values which will be appended to the existing vector.
  *
  * @param {int} *arr: the array we're appending arraySize: its size
  * @return {NULL} 
  */
   void pushBack (int *arr, int arraySize)  {
    for (int i = 0; i < arraySize; i++) {
      this->pushBack(*(&arr[i]));
    }
  }

};

/**
* Function constructor
*   Sets up the vector
* @param {int} size : initial size of vector 
* @return void
*/
myVector::myVector(int size){
  maxSize = size;
  minSize = size;
  // create the array of vSize
  vPtr = new int[maxSize];
  index = 0;
}

/**
* Function print
*   Prints the current values in the vector
* @param void  
* @return void
*/
void myVector::print(){
  for(int i=0;i<index;i++){
    cout<<vPtr[i]<<" ";
  }
  cout<<endl;
}

/**
* Function pushBack
*   Adds value to vector
* @param {int} item : integer value  
* @return void
*/
void myVector::pushBack(int item) {
  if(index >= maxSize){
    vPtr = resize(1.5);
  }
  vPtr[index++] = item;
}

/**
* Function popBack
*   Returns value from vector
* @param none 
* @return {int} : last item on vector
*/
int myVector::popBack(){

  index--;

  if(index < 0){
    //dammit
  }

  if(percentFull() <= .4){
    vPtr = resize(.5);
  }

  return vPtr[index];
}

/**
* Function resize
*   Resizes our vector based on passed in ratio
* @param {double} ratio : new array size 
* @return {int*} : pointer to new array
*/
int* myVector::resize(double ratio){
  // figure out what our new size is, bigger or smaller
  int newSize = maxSize * ratio;

  return _resize(newSize);
}

int* myVector::resize(int size){

  return _resize(size);
  
}

int* myVector::_resize(int newSize){
  // Lets keep our vector above some minimum size
  if(newSize < minSize){
    newSize = minSize;
  }

  // allocate new bigger vector
  int* vBigger = new int[newSize];

  //copy everything over
  for(int i=0;i<index;i++){
    vBigger[i] = vPtr[i];
  }

  // update new max size
  maxSize = newSize;

  // delete old memory
  delete [] vPtr;

  //return ptr to new memory
  return vBigger;
}

/**
* Function percentFull
*   helper function to calculate how full vector is
* @param none
* @return {double} : how full vector is
*/
double myVector::percentFull(){
  return double(index) / double(maxSize);
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
int myVector::size(){
  return index;
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
void myVector::size(int newSize){
  vPtr = _resize(newSize);
}

/**
* Function vSize
*    Returns actual size of allocated memory
* @param none
* @return {int} : mem size
*/
int myVector::vSize(){
  return maxSize;
}

// Overloading operators

 
  


