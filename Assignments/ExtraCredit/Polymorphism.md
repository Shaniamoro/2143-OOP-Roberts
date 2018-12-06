# Polymorphism in C++

 ## What is Polymorphism? 
> This is one of the **Four Pillars of OOP**
> The same interface (operator) existing in different forms is called polymorphism.
> In other words giving different meaning or functions to the operators or functions.
- Note : Poly refers to many. So you can think of it as a single function or an operator functioning in many ways different other than the original usage.
- *Example: 
    An addition between two integers 2 + 2 return 4
    whereas an addition between two strings "Hello" + "World" concatenates it to "Hello World"*

## Types of Polymorphism
1. Runtime Polymorphism (Late Binding):This is where the compiler adds code that identifies the type of object at runtime then matched the call with the right function definition. 

1. Compile time Polymorphism (Early Binding): The compiler directly associates an address to the function call. It replaces the call with a machiene language instruction that tells the mainframe to leap to the address of the function. 

## Runtime Polymorphism 
> This is achieved by function overloading and operator overloading

> **Function Overloading**
> When the existing operator or function is made to operate on new data type, it is said to be overloaded.
> When you overload a function you are defining a function with the same name and passing in different types of arguements or number of arguements. 
```
class Rectangle {
private:
	float width;
	float height;

public:
	int * Rect;
	static int count;
	Rectangle(); // Default does not pass in arguments
	Rectangle (int); // Passes in one argument of type integer 
	Rectangle(float, float); // Passes in two arguments of type float
	Rectangle(int, int); // Passes in two arguments of type int 
 };


```
> **Operator Overloading** 
> Redefining how an operator operates its operands is called operator overloading.
```
	// Overload the << operator (inline)
 // needs to be overloaded with the friend keyword to access private and protected members 
 // of the classs it is in.
	friend ostream& operator<<(ostream& os, const Rectangle &Rect) {
		os << "{ w:" << Rect.width << " , h:" << Rect.height << " }";
		return os;
	}
	
	//Overload the = operator (inline) 
	Rectangle& operator=(const Rectangle & Rect) {
		this->width = Rect.width;
		this->height = Rect.height;
		return *this;
	}
	// Overload the + operator (inline)
	Rectangle operator+(const Rectangle  &Rect) {
		Rectangle temp (this->width + Rect.width, this->height + Rect.height);
		count++;
		return temp;	
	}
```

## Compile time Polymorphism
> This is achieved by function overriding 
* Functon overriding 



The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form.
Real life example of polymorphism, a person at a same time can have different characteristic. Like a man at a same time is a father, a husband, a employee. So a same person posses have different behavior in different situations. This is called polymorphism.
Polymorphism is considered as one of the important features of Object Oriented Programming.
In C++ polymorphism is mainly divided into two types:

Compile time Polymorphism
Runtime Polymorphism
Compile time polymorphism: This type of polymorphism is achieved by function overloading or operator overloading. 

 

Function Overloading: When there are multiple functions with same name but different parameters then these functions are said to be overloaded. Functions can be overloaded by change in number of arguments or/and change in type of arguments.
Rules of Function Overloading
filter_none
edit
play_arrow

brightness_4
// C++ program for function overloading 
#include <bits/stdc++.h> 
  
using namespace std; 
class Geeks 
{ 
    public: 
      
    // function with 1 int parameter 
    void func(int x) 
    { 
        cout << "value of x is " << x << endl; 
    } 
      
    // function with same name but 1 double parameter 
    void func(double x) 
    { 
        cout << "value of x is " << x << endl; 
    } 
      
    // function with same name and 2 int parameters 
    void func(int x, int y) 
    { 
        cout << "value of x and y is " << x << ", " << y << endl; 
    } 
}; 
  
int main() { 
      
    Geeks obj1; 
      
    // Which function is called will depend on the parameters passed 
    // The first 'func' is called  
    obj1.func(7); 
      
    // The second 'func' is called 
    obj1.func(9.132); 
      
    // The third 'func' is called 
    obj1.func(85,64); 
    return 0; 
}  
Output:

value of x is 7
value of x is 9.132
value of x and y is 85, 64
In the above example, a single function named func acts differently in three different situations which is the property of polymorphism.

Operator Overloading: C++ also provide option to overload operators. For example, we can make the operator (‘+’) for string class to concatenate two strings. We know that this is the addition operator whose task is to add to operands. So a single operator ‘+’ when placed between integer operands , adds them and when placed between string operands, concatenates them.
Example:
filter_none
edit
play_arrow

brightness_4
// CPP program to illustrate 
// Operator Overloading 
#include<iostream> 
using namespace std; 
   
class Complex { 
private: 
    int real, imag; 
public: 
    Complex(int r = 0, int i =0)  {real = r;   imag = i;} 
       
    // This is automatically called when '+' is used with 
    // between two Complex objects 
    Complex operator + (Complex const &obj) { 
         Complex res; 
         res.real = real + obj.real; 
         res.imag = imag + obj.imag; 
         return res; 
    } 
    void print() { cout << real << " + i" << imag << endl; } 
}; 
   
int main() 
{ 
    Complex c1(10, 5), c2(2, 4); 
    Complex c3 = c1 + c2; // An example call to "operator+" 
    c3.print(); 
} 
Output:

12 + i9
In the above example the operator ‘+’ is overloaded. The operator ‘+’ is an addition operator and can add two numbers(integers or floating point) but here the operator is made to perform addition of two imaginary or complex numbers. To learn operator overloading in details visit this link.

Runtime polymorphism: This type of polymorphism is achieved by Function Overriding.
Function overriding on the other hand occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.
filter_none
edit
play_arrow

brightness_4
// C++ program for function overriding 
  
#include <bits/stdc++.h> 
using namespace std; 
  
class base 
{ 
public: 
    virtual void print () 
    { cout<< "print base class" <<endl; } 
   
    void show () 
    { cout<< "show base class" <<endl; } 
}; 
   
class derived:public base 
{ 
public: 
    void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly 
    { cout<< "print derived class" <<endl; } 
   
    void show () 
    { cout<< "show derived class" <<endl; } 
}; 
  
//main function 
int main()  
{ 
    base *bptr; 
    derived d; 
    bptr = &d; 
       
    //virtual function, binded at runtime (Runtime polymorphism) 
    bptr->print();  
       
    // Non-virtual function, binded at compile time 
    bptr->show();  
  
    return 0; 
}  
Output:

print derived class
show base class


Source: https://www.geeksforgeeks.org/polymorphism-in-c/
