/**
    *  Course: CMPS 3013 - Algorithms
    *  Assignment: A02
    *  Purpose: Demonstrate Overloading with Linked List
    * 
    *  @author Terry Griffin ; Shania Roberts 
    *  @version 1.1 09/05/18
    */

#include <iostream>

using namespace std;

int A[100];


// Declares a data structure type called Node
// which creates a container for list data 
struct Node
{
    // int x will be the actual value that will be
    // used in the various operations of the list 
    // eg. push, pop, insert, etc.
    int x;

    //This variable will be used as a pointer the next node in the list
    Node *next;

    //This is a constructor for the Node type when no 
    //argument is passed when it is declared; it then initializes
    // the x value to -1 and seeing that it is empty there will be no reference to next.
    Node()
    {
        x = -1;
        next = NULL;
    }

    //This is a constructor that accepts an integer value and 
    // initializes x to whatever was passed in the argument when that node is declared.                     
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

 /**
  * Class: List
  * Purpose: Implements a singly linked list that holds integers. 
  * Methods:
  *     void  Push (int val)
  *     void  Insert (int val)
  *     void  PrintTail()
  *     string Print()
  *     int Pop()
  *     List operator+(const List &Rhs)
  *     int operator[](int index)
  *     friend ostream &operator<<(ostream &os, List L)
  */

class List
{
  private:
    Node *Head;
    Node *Tail;
    int Size;

  public:
    //constructor that initializes the list when it is empty and first being declared.
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }

  /**
  * Adds an integer value to the end of the List  
  *
  * @param {int} val: integer value to insert into List 
  * @return {NULL}
  */ 

    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);
        // Checks if the List is empty 
        if (!Head && !Tail)
        {
        // If list isn't populated then Temp is added
            Head = Tail = Temp;
        }
        else
        {
        // If the List is not empty then the value is added to the end of the list
            Tail->next = Temp;
            Tail = Temp;
        }
        //Updates the size of the list when a value is added
        Size++;
    }

  /**
  * Adds an integer value to the top of the List  
  *
  * @param {int} val: integer value to insert into List 
  * @return {NULL}
  */ 
    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        //Updates the size of the list when a value is added
        Size++;
    }

   /**
  * Prints the integer value from the last Node in the List 
  *  @param {none} 
  *  @return {NULL}
  */

    void PrintTail()
    {
        cout << Tail->x << endl;
    }

  /**
  *  Function that returns the string representation of all the values in the list
  *   
  *  @param {none} 
  *  @return {string} list: a string  with the members of the list in order separated by "->".
  */

    string Print()
    {
        Node *Temp = Head;
        string list;

        // Checks if the List is empty 
        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }
 /**
  * Removes elements from the list 
  *
  *  @param {none} 
  *  @return {0}
  */
   
  //not implemented
  int Pop()
    {
        Size--;
        return 0; 
    }

 /**
  * Overloading the + operator to create a new list which
  *  is the concatenation of List 1 and List 2 
  *
  *  @param {object} Rhs: a List  
  *  @return {object} NewList: a list which is the concatenation of List 1 and List 2 
  */
    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }
        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

 /**
  * Implementation of [] operator.  
  * This function returns an int value as if the list were an array.
  *
  * @param {int} index: the index of the node we're searching ofr 
  * @return {object} Temp: returns the value of the Node at the index given
  */
    int operator[](int index)
    {
        Node *Temp = Head;
        // Checks if the index is within the range of the List 
        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {
            // If the Index is in bound, it loops through the list and 
            // returns the value of the Node at that index
            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

   /**
  *  Overloading the << operator to return an output stream of our List
  *  which can access private properties of the list by using "friend" 
  *
  *  @param {object, object} os: output stream  and L: List to be printed.
  *  @return {object} os: output stream of the values in the List
  */

    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};




int main(int argc, char **argv)
{

    List L1;
    List L2;

    // Populating L1 
    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);
    }

     // Populating L2
    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}
