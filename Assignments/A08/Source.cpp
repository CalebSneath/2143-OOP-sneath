///////////////////////////////////////////////////////////////////////////////
// 
// Author:           Caleb Sneath
// Email:            ansengor@yahoo.com
// Label:            A08
// Title:            Copy Constructor
// Course:           CMPS 2143
// Semester:         Spring 2021
//
// Description:
//       This program is build upon another program that created classes for 
//       rgb colors. This program completes several incomplete methods within
//       the preexisting rgb color class, and adds a new class with support for
//       dynamic arrays of the rgb color class. This program implements this 
//       class and then tests support for the ability to add new elements to 
//       an array of colors, then print them with cout, as well as swap colors.
//       
// Usage: 
//      - The basic visual studios compiler should work fine. Visual studios code
//          has not been tested however.
//      - Copy and paste Source.cpp into a new project folder. Press save.
//      - Press "Local Windows Debugger".
//      - The program should run.
//      
// Files:            
//      Source.cpp    : driver program 
//      
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;


/**
 * This is an implementation of our single color rgb class.
 * This was the original class. It is mostly identical,
 * although the setter and getter functions are now functional,
 * as well as the grayscale function.
 *
 */
class RgbColor {
    int r;                  //int 0-255 red
    int g;                  //int 0-255 green
    int b;                  //int 0-255 blue
public:
    RgbColor();             // default constructor
    RgbColor(int);          // overloaded 1
    RgbColor(int, int, int);  // overloaded 2

    //Sets RGB values respectively
    void SetR(int inR)      // setter red
    {
        r = inR;
    }
    void SetG(int inG)      // setter green
    {
        g = inG;
    }
    void SetB(int inB)         // setter blue
    {
        b = inB;
    }

    //Gets RGB values respectively
    int GetR()              // getter red
    {
        return r;
    }
    int GetG()              // getter green
    {
        return g;
    }
    int GetB()              // getter blue
    {
        return b;
    }

    void GrayScale()        // averages colors
    {
        b = g = r = ((r + g + b) / 3);
    }

    // print to stdout
    friend ostream& operator<<(ostream&, const RgbColor&);

    // add (mix) two colors
    RgbColor operator+(const RgbColor&);

};


/**
 * ColorPallette
 *
 * Description:
 *      This class creates a dynamically allocated array of "RgbColor" objects.
 *      It also implements support for several operator overloads.
 *      Other things include functions for adding or changing stored rgb objects.
 * Usage:
 *    Public:
 *      RgbColor():                                 // Default constructor,
 *                                                  // Makes a one element array
 *                                                  // storing the rgb for black
 *      ColorPallette(RgbColor initialColor)        // Nondefault constructor,
 *                                                  // makes a one element array
 *                                                  // of the RgbColor passed from
 *                                                  // the user.
 *      ColorPallette(int rValue, int gValue, int bValue)//Nondefault constructor,
 *                                                  // makes a one element array
 *                                                  // of the RgbColor from 
 *                                                  // separate red, green, and 
 *                                                  // blue values passed.
 *      void addColor(RgbColor desiredColor)        // Generates a new array
 *                                                  // that is one element larger
 *                                                  // than the previous one.
 *                                                  // Then, it copies the 
 *                                                  // previous array to it.
 *                                                  // After copying values to 
 *                                                  // this new temporary array,
 *                                                  // the RgbColor passed to this
 *                                                  // function is added to the 
 *                                                  // remaining empty array address
 *                                                  // and the original array is 
 *                                                  // destroyed to copy the 
 *                                                  // temporary array.
 *      void addColor(int rValue, int gValue, int bValue)// And overload of the
 *                                                  // above function, with the
 *                                                  // only difference that it
 *                                                  // takes separate red, green
 *                                                  // and blue values instead
 *                                                  // of the RgbColor class.
 *      void setColor(RgbColor desiredColor, int targetColor) // Changes
 *                                                  // existing array color
 *                                                  // to RgbColor passed in
 *      void setColor(int rValue, int gValue, int bValue, int targetColor)
 *                                                  // Overload of above that
 *                                                  // instead accepts separate
 *                                                  // red, green, blue values
 *      friend ostream& operator<<(ostream&, const ColorPallette&);// Overloads
 *                                                  // << operator to print out
 *                                                  // the entire color pallette
 *                                                  // such as when cout
 *      bool operator==(const ColorPallette& rhs)   // Overloads the == 
 *                                                  // comparison operator to 
 *                                                  // return true if both 
 *                                                  // arrays are the same size
 *                                                  // and have the same element
 *                                                  // for the same position for 
 *                                                  // each position in the array
 *                                                  // and false otherwise
 *      ColorPallette &operator=(const ColorPallette& rhs) // Overloads = 
 *                                                  // assignment operator to 
 *                                                  // set the pallette object
 *                                                  // on left to be the same
 *                                                  // as the pallette object
 *                                                  // on the left.
 *      ColorPallette(const ColorPallette& rhs)     // A deep copy constructor.
 *                                                  // Makes a new object with
 *                                                  // identical values but 
 *                                                  // separate memory addresses
 *      ~ColorPallette()                            // The destructor. Frees
 *                                                  // up allocated dynamic array
 *                                                  // memory from colorCollection
 */
class ColorPallette {
    private: 
        int palletteSize;

    public:
        RgbColor* colorCollection = new RgbColor[1];
        ColorPallette()//Default constructor begins with 1 black color
        {
            RgbColor* colorCollection = new RgbColor[1];
            colorCollection[0] = RgbColor();
            palletteSize = 1;
        }
        //Overloaded constructor that begins with one initial color
        //Takes a dedicated RgbColor class as input
        ColorPallette(RgbColor initialColor)
        {
            RgbColor* colorCollection = new RgbColor[1];
            colorCollection[0] = initialColor;
            palletteSize = 1;
        }
        //Overloaded constructor that begins with one initial color
        //Takes raw red, green, and blue values as input
        ColorPallette(int rValue, int gValue, int bValue)
        {
            RgbColor* colorCollection = new RgbColor[1];
            colorCollection[0] = RgbColor(rValue,gValue,bValue);
            palletteSize = 1;
        }

        //Adds a new color to the pallette directly of RgbColor class.
        void addColor(RgbColor desiredColor)
        {
            //set up new temporary array to hold values
            //and copy existing values to it
            RgbColor* tempCollection = new RgbColor[palletteSize+1];

            copy(colorCollection, (colorCollection + palletteSize), tempCollection);

            //add new color to temporary array
            tempCollection[palletteSize].SetB(desiredColor.GetB());
            tempCollection[palletteSize].SetR(desiredColor.GetR());
            tempCollection[palletteSize].SetG(desiredColor.GetG());

            palletteSize++;

            //copy temporary array to proper array
            colorCollection = tempCollection;
        }//Overload that adds a new color to pallette from raw rgb values
        void addColor(int rValue, int gValue, int bValue)
        {
            //set up new temporary array to hold values
            //and copy existing values to it
            RgbColor* tempCollection = new RgbColor[palletteSize + 1];

            copy(colorCollection, (colorCollection + palletteSize), tempCollection);

            //add new color to temporary array
            tempCollection[palletteSize].SetB(bValue);
            tempCollection[palletteSize].SetR(rValue);
            tempCollection[palletteSize].SetG(gValue);

            palletteSize++;

            //copy temporary array to proper array
            colorCollection = tempCollection;
        }

        //Changes colors for an array element that already exists
        void setColor(RgbColor desiredColor, int targetColor)
        {
            colorCollection[targetColor] = desiredColor;
        }
        void setColor(int rValue, int gValue, int bValue, int targetColor)
        {
            colorCollection[targetColor] = RgbColor(rValue, gValue, bValue);
        }

        //Prints entire pallette to stdout. 
        friend ostream& operator<<(ostream&, const ColorPallette&);

        //Overloads comparison operator
        bool operator==(const ColorPallette& rhs)
        {
            //Stores if the two ColorPallettes are the same
            bool diffCheck = true;

            if (palletteSize == rhs.palletteSize)
            {
                //Compares each two element, setting diffcheck to true if a
                //different one is found. Runs as many times as right hand
                //side has array elements
                for (int loopCount = 0; loopCount < rhs.palletteSize; loopCount++)
                {
                    if (colorCollection->GetB() == rhs.colorCollection->GetB())
                    {
                        //Nothing need be done
                    }
                    else
                    {
                        //A difference has been found and the loop
                        //can be exited early
                        diffCheck = false;
                        loopCount = rhs.palletteSize;
                    }

                    if (colorCollection->GetG() == rhs.colorCollection->GetG())
                    {
                        //Nothing need be done
                    }
                    else
                    {
                        //A difference has been found and the loop
                        //can be exited early
                        diffCheck = false;
                        loopCount = rhs.palletteSize;
                    }

                    if (colorCollection->GetR() == rhs.colorCollection->GetR())
                    {
                        //Nothing need be done
                    }
                    else
                    {
                        //A difference has been found and the loop
                        //can be exited early
                        diffCheck = false;
                        loopCount = rhs.palletteSize;
                    }
                }

            }
            else
            {
                diffCheck = false;//Can't be the same if array size is off
            }


            return diffCheck;
        }

        //Overloads assignment operator
        ColorPallette &operator=(const ColorPallette& rhs)
        {
            if (this == &rhs)//Avoid self assignment
            {
                return *this;
            }

            //Erases previous values to clean memory and start fresh
            palletteSize = 0;
            delete[] colorCollection;
            colorCollection = nullptr;

            //Recreates colorCollection with correct size
            colorCollection = new RgbColor[rhs.palletteSize];
            palletteSize = rhs.palletteSize;

            //Fills in values for colorCollection
            copy(rhs.colorCollection, (rhs.colorCollection + 
                palletteSize), colorCollection);

            return *this;
        }

        //Copy Constructor
        ColorPallette(const ColorPallette& rhs) {
            palletteSize = 0;
            delete[] colorCollection;
            colorCollection = nullptr;
            colorCollection = new RgbColor[rhs.palletteSize];
            palletteSize = rhs.palletteSize;


            copy(rhs.colorCollection, (rhs.colorCollection + 
                palletteSize), colorCollection);

        }

        //Destructor
        ~ColorPallette()
        {   
            delete[] colorCollection;
        }
};

//+ assignment operator overload that adds values
//then averages them out.
RgbColor RgbColor::operator+(const RgbColor& rhs) {
    int r = (this->r + rhs.r) / 2;
    int g = (this->g + rhs.g) / 2;
    int b = (this->b + rhs.b) / 2;

    return *this;
}

//Default constructor that makes black
RgbColor::RgbColor() {
    r = g = b = 0;
}
//Overloaded constructor for grayscale of passed value
RgbColor::RgbColor(int color) {
    r = g = b = color;
}
//Overloaded constructor for individualized values
RgbColor::RgbColor(int _r, int _g, int _b) {
    r = _r;
    g = _g;
    b = _b;
}

//Prints out color in [r,g,b] format.
ostream& operator<<(ostream& os, const RgbColor& rhs) {
    os << "[" << rhs.r << "," << rhs.g << "," << rhs.b << "]";
    return os;
}

//Prints pallette in [ [color1] [color2] [etc.] ] format
ostream& operator<<(ostream& os, const ColorPallette& rhs) {
    os << "[ ";
    for (int loopCount = 0; loopCount < rhs.palletteSize; loopCount++)
    {
        os << rhs.colorCollection[loopCount] << " ";
    }
    os << "]";
    return os;
}

int main() {
    cout << "Caleb Sneath A08 2143" << endl;
    cout << "Copy Constructor" << endl << endl;

    RgbColor Color1(255, 200, 11);
    RgbColor Color2(100, 14, 123);
    RgbColor Color3 = Color1 + Color2;
    cout << Color3 << endl;

    //All code below tests and demonstrates the use
    //of copy constructors as well as dynamically allocated
    //arrays of objects.
    ColorPallette testPallette1(Color3);
    testPallette1.colorCollection[0] = Color3;
    cout << testPallette1 << endl;

    cout << "This tests if adding a color ";
    cout << "to the pallette works." << endl;
    cout << "It also tests if interacting with individual ";
    cout << "colors works correctly." << endl;
    testPallette1.setColor(Color1, 0);
    cout << testPallette1.colorCollection[0].GetG() << endl;
    testPallette1.addColor(Color3);

    cout << endl << "This tests if printing an entire pallette";
    cout << " works correctly." << endl;
    cout << testPallette1.colorCollection[0] << endl;
    cout << testPallette1.colorCollection[1] << endl;
    cout << testPallette1 << endl << endl;

    cout << "This tests if the pallette can handle having ";
    cout << "a bunch of random colors added." << endl;
    testPallette1.addColor(Color2);
    testPallette1.addColor(3, 222, 6);
    testPallette1.addColor(Color3);
    testPallette1.addColor(Color1);
    testPallette1.addColor(30, 2, 103);
    testPallette1.addColor(42, 27, 99);
    cout << testPallette1 << endl << endl;

    ColorPallette testPallette2 = testPallette1;

    cout << "This tests if the copy constructor worked." << endl;
    cout << "It also tests if the comparison works." << endl;
    cout << testPallette2;
    if (testPallette1 == testPallette2)
    {
        cout << endl << "They are the same." << endl;
    }
    else
    {
        cout << endl << "They are different." << endl << endl;
    }


    cout << "This tests if the copy constructor makes a ";
    cout << "deep copy properly." << endl;
    testPallette1.setColor(7, 7, 7, 0);
    cout << testPallette1 << endl;
    cout << testPallette2 << endl;
    if (testPallette1 == testPallette2)
    {
        cout << endl << "They are the same." << endl;
    }
    else
    {
        cout << endl << "They are different." << endl;
    }

    cout << endl << "This tests self assignment" << endl;
    testPallette1 = testPallette1;
    cout << testPallette1 << endl << endl;
}