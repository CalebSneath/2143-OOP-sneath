## A05

- Name: Caleb Sneath
- Date: 27 Jan 2021
- Class: 2143 OOP

## Definitions

#### Abstraction
> Bundling together bits of information in a way that allows it to be used 
> for some particular purpose without necessarily needing to know the specifics
> of that information. 

#### Attributes / Properties
> Attributes are the data within a class. For example, a class called "Television"
> might have an attribute of type string called "type", which is inputted as 
> "LCD" by the user at runtime.

#### Class
> Classes are some code that serves the purpose of being the template to make an
> object. Classes can specify different attributes and methods that will be a 
> part of the objects they create. One thing which distinguishes classes and 
> structs however, is that classes have support for being able to restrict access
> to certain parts such as through declaring them to be either private or public.

#### Class Variable
> Variables that are, as the name suggests, defined within the class. These 
> are different from class methods. What separates this from an instance variable
> however is that there is only a single class variable shared among all members 
> of the same class. For this reason, they are sometimes referred to as static 
> member variables

#### Composition
> Being formed from the combination of several smaller categories of 
> characteristics. In object oriented programming, many classes are composed of 
> a composition of many other classes. For example, assume there is a class 
> called "Computer". This computer could be composed of another class called
> "Graphics Card" which contains information on the computers CPU, and another
> class called "CPU", which contains variables related to the central processing
> unit.

#### Constructor
> A method within a class which runs whenever a class is initialized. Generally, 
> the constructor is used to set different elements within the class to its 
> normal starting values. Depending on the values that are passed to a class on 
> creation and the methods set up by the creator of the class, the class can be
> set to use a default constructor, or a nondefault constructor. Multiple 
> nondefault constructors can be set up in advance for different possible data 
> types by overloading the constructor methods.

#### Encapsulation
> As the name suggests, encapsulation is the bundling together of related data, 
> as if in a "capsule". Most of the data is inaccessible to outside users and 
> code, and can only be modified by going through the intermediary, the capsule
> in this analogy. This serves to preserve data integrity, maintain security, 
> as well as logically and spacially connect related code. For example, in C++,
> a class's private elements can only be affected by the class itself, or any 
> friend methods.

#### Friends
> Methods assigned with friend status are methods which aren't members of the 
> class, however they have been granted authorization to modify and access the
> private elements of the class.

#### Inheritance
> Using elements from one class for the creation of another. This can allow
> a class to be used in a hierarchy of classes, where one class obtains
> elements from one, and another class can be designed to obtain elements from 
> it in turn.

#### Instance Variable
> Variables that are, defined within the class. However, unlike class variables,
> each object has their own instance variable that isn't shared among every instance
> of that class.

#### Member Variable
> Variables that are, defined within the class. This is a larger category of 
> variable that contains class variables as well as instance variables.

#### Method
> Methods are basically a bundle of code which the user defines and can 
> call to use throughout a class. Methods are not directly data itself, 
> they are more like instructions.

#### Multiple Inheritance
> Whenever a programming language allows a class to use the elements of 
> more than one other class for its creation. For example, if there are 
> two classes, "Bottle" and "DairyItems", a class called "MilkJug" 
> might be implemented to obtain data from both classes during its 
> creation.

#### Object
> Objects are just individual instances of a specific class. In other 
> terms, while a class is like the blueprint, an object is like the actual
> house. Like blueprints, it's possible to use the same blueprints to 
> build multiple of the same house under the right circumstances.

#### Overloading
> Overloading is when you prepare multiple versions of a method that are 
> set up to handle different types of inputs. A common example of this is 
> if you have a method that gets passed a number. It's possible the 
> number may sometimes be an integer when the programmer calls the 
> method, but other times it gets handed a floating point number. 
> With overloading, this isn't a problem because the compiler will link
> to the version of the method that was designed to handle the integer
> or floating point as necessary.

#### Polymorphism
> Polymorphism roughly means that something can have several different 
> forms. A good example is when you overload a method. Depending on 
> how your code is programmed, the same method name could be paired
> to different lines of code for the overloaded method throughout 
> the program.

#### Public / Private / Protected
> Defines the access right requirement for different parts of a
> class. Public is freely accessible to everyone. Private is only
> available to the object itself as well as friend methods. 
> Protected is a bit more open than private in that it allows
> different objects to access it so long as they share a class.

#### Static
> A variable which survives the entire length of the program
> by default after being called. In contrast, to a normal 
> variable, which only lasts as long as the normal scope of
> its creation entails, a static variable will continue even
> if the method which created it ends.

#### Virtual
> Any method or class that inherits the virtual keyword can be 
> overridden during runtime. 
