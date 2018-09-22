 ### Shania Roberts
 ### Date : Sept 28th 
 ### Class: 2143 OOP

# Definitions 
## Class 
> A class is logical grouping of attributes(variables) and methods(functions)
><img src="https://upload.wikimedia.org/wikipedia/commons/6/62/CPT-OOP-objects_and_classes.svg" width=400>

## Object
> This is the basic unit of object oriented programming. An object is an instance 
> of a class that has access to all the attributes and methods of that class.

## Method
> A function within a class that performs a speciﬁc action is called a method belonging to that class. 
- There are two types of methods:
1. Static method 
1. Instance method


## Abstraction
> Abstraction is the process of steps followed to achieve encapsulation.It works by providing only essential 
> information to the outside world and hiding their background details.
- For example, a database system hides certain details of how data is stored and created and maintained.
  
## Encapsulation
> Encapsulation is placing the data and the functions that work on that data in the same place.
> Basically, hiding the implementation details from the end user.
- While working with procedural languages, it is not always clear which functions work on which variables but object-oriented programming provides you framework to place the data and the relevant functions together in the same object.
	
 ## Polymorphism
> The same interface (operator)  existing in different forms is called polymorphism.
> In other words giving different meaning or functions to the operators or functions.
- Note : Poly refers to many. So you can think of it as a single function or an operator functioning in many ways different other than the original usage.
- *Example: 
    An addition between two integers 2 + 2 return 4
    whereas an addition between two strings "Hello" + "World" concatenates it to "Hello World"*
        
## Overloading (Operator)
> Redefining how an operator operates its operands is called operator overloading.
> When the exiting operator or function is made to operate on new data type, it is said to be overloaded.

 ## Attributes / Properties
> Data members are attributes declared within a class. 
> They are properties that further deﬁne a class.
- There are two types of attributes: 
 1. Class attributes and
 2. Instance attributes	  
  
## Class Variable
> An attribute that is common across all instances of a class is called a class attribute.
-Because they are owned by the class itself, class variables are shared by all instances of the class.
They therefore will generally have the same value for every instance unless you are using the class variable to initialize a variable.

## Instance Variable
> An attribute that is speciﬁc to each instance of a class is called an instance attribute.
- This means that for each object or instance of a class, the instance variables are different.
  
## Member Variable
> A member variable is a variable that is associated with a specific object, and is accessible for all its methods.
- It must be declared within a class, but not within the body of a method of the class.

## Inheritance
> Inheriting the attributes and methods of a base class into a derived class is called Inheritance.
- It helps to reduce the code size since you can reuse existing code with little to no modification.
><img src="https://www.studytonight.com/cpp/images/inheritance-example.jpg" width=400>

## Multiple Inheritance
> Mechanism in which a derived class inherits from two or more base classes is called a multiple inheritance
><img src="https://cdn.programiz.com/sites/tutorial2program/files/c%2B%2Bmultiple-inheritance.jpg" width=400>

## Composition
> This process of building complex objects from simpler ones is called object composition.
- Relationship between objects where one object owns or *has* the other object 
- a car *has* a body
- a car *has* an engine
- a car *has* wheels
