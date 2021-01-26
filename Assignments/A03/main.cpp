///////////////////////////////////////////////////////////////////////////////
// 
// Author:           Caleb Sneath (Most comments), Terry Griffin (Code, template)
// Email:            ansengor@yahoo.com, terry.griffin@msutexas.edu
// Label:            A03
// Title:            Basic Project Organization
// Course:           CMPS 2143
// Semester:         Spring 2021
//
// Description:
//       This program implements a class that allows an array to be used as a circular que.
//       It creates a class that makes and accesses an array with a pointer. Then, using 
//       functions within the class, it does the actions necessary to create the "pop" and
//       "push" effects for the que. As the name describes, it makes use of the modulus 
//       operator for some of its logic to "wrap around" to the start of the que. Although
//       this code demonstrates the creation of these circular arrays, the main purpose of
//       this project is to demonstrate proper commenting practice and project management.
//       
// Usage: 
//      - $ ./main filename
//      - This will read in a file containing whatever values to be read into our array. 
//      
// Files:            
//      main.cpp    : driver program 
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *      This class creates an array using a pointer using the constructor. 
 *      Afterward, using the pop and push functions within, it adds and removes
 *      elements in order to create a circular array que like its name suggests.
 *      The "circular" portion comes from the fact that the array elements wrap 
 *      around eventually to the beginning.
 * 
 * Public Methods:
 *                          CircularArrayQue()
 *                          CircularArrayQue(int size)
 *      void                Push(int item)
 *      int                 Pop()
 *      friend ostream&     operator<<(ostream &os, const CircularArrayQue &other);
 * 
 * Private Methods:
 *      int                *Container
 *      int                Front
 *      int                Rear
 *      int                QueSize
 *      int                CurrentSize
 *      void               init(int size = 0)
 *      bool               Full()
 * 
 * Usage: 
 * 
 *      CircularArrayQue():                         // Default constructor, generates
 *                                                  // an array of size 10.
 *      CircularArrayQue(int size):                 // Nondefault constructor, accepts
 *                                                  // int size and generates an array 
 *                                                  // of a matching size.
 *      Push(int item)                              // Takes int item and checks if 
 *                                                  // the array is full. If it's got 
 *                                                  // more space, it adds it to the 
 *                                                  // end or uses modulus to wrap it 
 *                                                  // around ot the beginning. If full,
 *                                                  // it warns the user. When applicable,
 *                                                  // it increments and updates Rear and 
 *                                                  // CurrentSize.
 *      Pop()                                       // Sets int temp to the front of the array
 *                                                  // and using modulus to adjust for
 *                                                  // any wrapping changes the front 
 *                                                  // of the array. Finally, it returns
 *                                                  // temp after decrementing CurrentSize.
 *      friend ostream& operator <<(ostream &os, const CircularArrayQue &other)
 *                                                  // Overloads os with other. 
 *      int *Container                              // A pointer to store the array address
 *      int Front                                   // Contains the number of the current front
 *                                                  // of the array. Usually put in the array "[]"s
 *      int Rear                                    // Contains the number of the current rear
 *                                                  // of the array. Usually put in the array "[]"s
 *      int QueSize                                 // Counts total capacity of array
 *      int CurrentSize                             // Counts used capacity of array
 *      void init (int size = 0)                    // Initializes most values in the que
 *      bool Full()                                 // Checks if Que is full and returns true if so 
 */
class CircularArrayQue {
private:
    int *Container;     // A pointer that will have the address of the array.
    int Front;          // Front of the array, but since it is circular,
                        // sometimes it will be "lower" than Rear
    int Rear;           // Rear of array, but since it is circular, sometimes
                        // it is "higher" than Front
    int QueSize;        // max size of this array
    int CurrentSize;    // used space in arry
    
     /**
     * Private : void init
     * 
     * Description:
     *      Initializes most array variablesto zero and sets QueSize to size.
     * 
     * Params:
     *      int size:  Initialized to zero
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size; // On initialization, the array is empty, and so are
                        // all of the variables in this function.
    }

    /**
     * Private : bool Full()
     * 
     * Description:
     *      Checks if the array is at its max size and returns 
     *      true if so.
     * 
     * Returns:
     *      The result of comparing if CurrentSize equals QueSize
     */
    bool Full() {
        return CurrentSize == QueSize; //True if full, false if empty
    }

public:

    /**
     * Public : CircularArrayQue()
     * 
     * Description:
     *      Default constructor, sets array size to 10
     */
    CircularArrayQue() {
        Container = new int[10];      //Defaults to array size 10
        init(10);                     
    }

     /**
     * Public : CircularArrayQue()
     * 
     * Description:
     *      Nondefault constructor, uses variable int size
     *      to decide array size.
     * 
     * Params:
     *      int size     :  size of array
     */
    CircularArrayQue(int size) {
        Container = new int[size];  // Allocates memory for array of
                                    // size "size"
        init(size);
    }

    /**
     * Public : void Push(int item)
     * 
     * Description:
     *      Adds item to the array que. Utilizes an if statement to
     *      check if full, and either continues or displays error 
     *      message. Modulus operations are used to wrap around.
     *      Current size is updated as needed.
     * 
     * Params:
     *      int item    :  element to be added to array
     */
    void Push(int item) {
        if (!Full()) {                    // Checks if full, does else if so
            Container[Rear] = item;       
            Rear = (Rear + 1) % QueSize;  // Remainder useful for "wrapping
                                          // around" circular array
            CurrentSize++;                // Current size increases when 
                                          // adding items
        } else {                          // Error message for when full
            cout << "FULL!!!!" << endl;
        }
    }

    /**
     * Public :  int Pop()
     * 
     * Description:
     *      Removes an item from the array que and updates
     *      CurrentSize and Front. Returns temp, an integer set at the 
     *      beginning from the front of the que.
     * 
     * Returns:
     *      temp   : stores the front of the que
     */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;    // Remainder useful for 
                                          // "wrapping around circular array
        CurrentSize--;                    // Array shrinks when removing item
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    // Calls CircularArrayQue function to create a circular array que, named "C1"
    // and initializes its size to five.
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    // Pushes 1, 2, and 3 to C1 ussing the "Push" function it contains. Then uses
    // cout to display the array.
    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    // Uses cout to display the array.
    cout << C1 << endl;
}
