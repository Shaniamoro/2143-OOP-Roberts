# Virtual Function in C++

 ## What is a virtual function? 
> This is a function that is inheritable and overridable in a derived class.
> When trying to invoke an object from the derived class by using a pointer or a reference to the base class, the virtual function for that specific object can be used to execute the derived class's version of the function.  
> With virtual functions, you can achieve runtime polymorphism as the function which will be executed is chosen at runtime.

## Example: 
> **Illustrating the use of virtual functions** <br />
> Here we will see two functions in the Parent Class; one being virtual while the other is not.
> The function that is virtual `print()` will show the result for the child class as it binds at runtime when it is referenced from the parent class; the parent class pointer `pc_ptr` has the address of the object `child_class` <br />
> However, the function that is not virtual is binded during compile time. 
```
    // Exemplifying the concept of Virtual Functions 
    #include<iostream> 
    using namespace std; 
    
    class ParentClass { 
    public: 
        virtual void print() {
            cout << "Print Parent Class" << endl; 
        } 
    
        void show() { 
            cout << "Show Parent Class" << endl; 
        } 
    }; 
    
    class ChildClass:public ParentClass { 
    public: 
        void print () { 
            cout<< "Print Child Class" <<endl;
        } 
    
        void show () { 
            cout<< "Show Child Class" <<endl; 
        } 
    }; 
    
    int main() { 
        ParentClass *pc_ptr; 
        ChildClass child_class; 
        pc_ptr = &child_class; 
        
        //virtual function which is binded at runtime 
        pc_ptr->print();  
        
        // Non-virtual function which is binded at compile time 
        pc_ptr->show();  
    } 


```

### Output
```
> Print Child Class
> Show Parent Class
```

### The following Rules must be followed when implementing Virtual Functions
1. They are declared in public section of class.
2. Virtual functions cannot be static and also cannot be a friend function of another class.
3. Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
4. The prototype of virtual functions should be same in base as well as derived class. (same signatures) 
5. They are always defined in base class and overridden in derived class. It is not mandatory for derived class to override (or re-define the virtual function), in that case base class version of function is used.
6. A class may have a virtual destructor but it cannot have a virtual constructor.

Note: There are additional rules for Pure Virtual Functions. 


- Source: https://www.geeksforgeeks.org/virtual-function-cpp/
