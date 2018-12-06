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
> We are able to overload almost all operators in C++ except for ** . , :: , ?: , sizeof . 
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
> Operator overloading is important when we are dealing with user defined classes. 

#### Important Points on Operator Overloading 
 1. For operator overloding to work one must be a user defined class object 
 1. The complier will overload the assignment operator (=) by default, it assings the object on the left hand side of the operator with the values of the object on the right side of the operator.
 1. The Conversion operator, which converts one type to another type must be a member method. 
 1. Any constructor that can be called with a single argument works as a conversion constructor, means it can also be used for implicit conversion to the class being constructed. 
 
 

## Compile time Polymorphism
> This is achieved by function overriding 
> Function overriding occurs when a function in the Base class is defined using the virtual keyword and is then redifined in the member class.
* Functon overriding 
```
using namespace std;

class Animal { 
public: 
    void isAlive(){
      cout<< "Base: This Animal is alive"<<endl;
    }
    virtual void fly(){
       cout << "Base: Doesn't fly"<<endl; } 
}; 
  
class Cat : public Animal 
{ 
public: 
void fly() override{
       cout << "Derived: Cats Don't fly" <<endl; } 
}; 
class Bird : public Animal 
{ 

}; 
  
int main() 
{ 
    Bird b;
    Cat c; 
    // This method is overridden so it will be printing what's defind in the derived class.
    c.fly();
    // This method isn't overridden for the Cat so it will be printing for the base
    b.fly();
}
```








- Source: https://www.geeksforgeeks.org/virtual-function-cpp/
- Source: https://www.geeksforgeeks.org/operator-overloading-c/
- Source: https://www.geeksforgeeks.org/polymorphism-in-c/
