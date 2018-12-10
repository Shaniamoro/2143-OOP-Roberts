# Virtual Function in C++

 ## What is a virtual function? 
> This is a function that is inheritable and overridable in a derived class.
> When trying to invoke an object from the derived class by using a pointer or a reference to the base class, the virtual function for that specific object can be used to execute the derived class's flavor of the function.  
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

- Source: https://www.geeksforgeeks.org/virtual-function-cpp/
