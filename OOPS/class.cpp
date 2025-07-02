//public : can be accessed from anywhere
//private : can only be accessed within the class
//protected : can be accessed within the class and by the child classes
/*
Object-Oriented Programming (OOP) is a programming paradigm based on the concept of "objects", which can contain data and code: data in the form of fields (often known as attributes or properties), and code, in the form of procedures (often known as methods).

The four main pillars of OOP are:
1. Encapsulation
2. Inheritance
3. Polymorphism
4. Abstraction

Let's discuss each concept in detail with C++ examples.

----------------------------------------
1. Encapsulation
----------------------------------------
Encapsulation is the bundling of data and methods that operate on that data within one unit, e.g., a class. It restricts direct access to some of the object's components, which is a means of preventing unintended interference and misuse.

Example:
*/
#include <iostream>
#include <string>
using namespace std;

class EncapsulatedStudent {
private:
    string name;
    int age;
public:
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    string getName() { return name; }
    int getAge() { return age; }
};
/*
Here, 'name' and 'age' are private and can only be accessed via public methods.

----------------------------------------
2. Inheritance
----------------------------------------
Inheritance allows a class (derived class) to inherit properties and behavior (methods) from another class (base class).

Example:
*/
class Animal {
public:
    void eat() { cout << "Eating..." << endl; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Barking..." << endl; }
};
/*
Inheritance is a fundamental concept in Object-Oriented Programming (OOP) that allows one class (called the derived or child class) to acquire the properties and behaviors (methods and data members) of another class (called the base or parent class). This helps in code reusability and establishing a relationship between classes.

Let's explain each type of inheritance in C++ with examples:

1. Single Inheritance:
   - A single derived class inherits from a single base class.

Example:
*/
class Parent {
public:
    void showParent() { cout << "This is the Parent class." << endl; }
};
class Child : public Parent {
public:
    void showChild() { cout << "This is the Child class." << endl; }
};
/*
Usage:
Child c;
c.showParent(); // Output: This is the Parent class.
c.showChild();  // Output: This is the Child class.

2. Multiple Inheritance:
   - A single derived class inherits from more than one base class.

Example:
*/
class A {
public:
    void showA() { cout << "Class A" << endl; }
};
class B {
public:
    void showB() { cout << "Class B" << endl; }
};
class C : public A, public B {
public:
    void showC() { cout << "Class C" << endl; }
};
/*
Usage:
C obj;
obj.showA(); // Output: Class A
obj.showB(); // Output: Class B
obj.showC(); // Output: Class C

3. Multilevel Inheritance:
   - A class is derived from another derived class, forming a "chain" of inheritance.

Example:
*/
class Grandparent {
public:
    void showGrandparent() { cout << "Grandparent class" << endl; }
};
class Parent2 : public Grandparent {
public:
    void showParent2() { cout << "Parent2 class" << endl; }
};
class Child2 : public Parent2 {
public:
    void showChild2() { cout << "Child2 class" << endl; }
};
/*
Usage:
Child2 c2;
c2.showGrandparent(); // Output: Grandparent class
c2.showParent2();     // Output: Parent2 class
c2.showChild2();      // Output: Child2 class

4. Hierarchical Inheritance:
   - Multiple derived classes inherit from a single base class.

Example:
*/
class Base {
public:
    void showBase() { cout << "Base class" << endl; }
};
class Derived1 : public Base {
public:
    void showDerived1() { cout << "Derived1 class" << endl; }
};
class Derived2 : public Base {
public:
    void showDerived2() { cout << "Derived2 class" << endl; }
};
/*
Usage:
Derived1 d1;
d1.showBase();      // Output: Base class
d1.showDerived1();  // Output: Derived1 class

Derived2 d2;
d2.showBase();      // Output: Base class
d2.showDerived2();  // Output: Derived2 class

5. Hybrid Inheritance:
   - Combination of two or more types of inheritance.

Example:
   Let's combine multiple and hierarchical inheritance:
*/
class X {
public:
    void showX() { cout << "Class X" << endl; }
};
class Y : public X {
public:
    void showY() { cout << "Class Y" << endl; }
};
class Z {
public:
    void showZ() { cout << "Class Z" << endl; }
};
class Hybrid : public Y, public Z {
public:
    void showHybrid() { cout << "Hybrid class" << endl; }
};
/*
Usage:
Hybrid h;
h.showX();      // Output: Class X (inherited via Y)
h.showY();      // Output: Class Y
h.showZ();      // Output: Class Z
h.showHybrid(); // Output: Hybrid class

Summary:
- Single Inheritance: One base, one derived.
- Multiple Inheritance: Multiple bases, one derived.
- Multilevel Inheritance: Derived from a derived class.
- Hierarchical Inheritance: One base, multiple derived.
- Hybrid Inheritance: Combination of above.

Each type of inheritance helps in different scenarios to promote code reuse and logical relationships between classes.
*/
/*
----------------------------------------
3. Polymorphism
----------------------------------------
Polymorphism means "many forms". It allows us to perform a single action in different ways.

Types:
- Compile-time (Function/Operator Overloading)
- Run-time (Virtual Functions)

a) Compile-time Polymorphism (Function Overloading)
*/
class Print {
public:
    void show(int i) { cout << "Integer: " << i << endl; }
    void show(double d) { cout << "Double: " << d << endl; }
    void show(string s) { cout << "String: " << s << endl; }
};
/*
b) Run-time Polymorphism (Virtual Functions)
*/
class Base {
public:
    virtual void display() { cout << "Display of Base" << endl; }
};
class Derived : public Base {
public:
    void display() override { cout << "Display of Derived" << endl; }
};
/*
If you call display() using a Base pointer to a Derived object, the Derived version is called.

----------------------------------------
4. Abstraction
----------------------------------------
Abstraction means hiding complex implementation details and showing only the necessary features.

In C++, abstraction is achieved using abstract classes (classes with at least one pure virtual function).

Example:
*/
class AbstractShape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public AbstractShape {
public:
    void draw() override { cout << "Drawing Circle" << endl; }
};

class Rectangle : public AbstractShape {
public:
    void draw() override { cout << "Drawing Rectangle" << endl; }
};
/*
You cannot instantiate AbstractShape, but you can use pointers/references to it.

----------------------------------------
5. Constructors and Destructors
----------------------------------------
Constructors are special methods called when an object is created. Destructors are called when an object is destroyed.

Example:
*/
class Person {
public:
    Person() { cout << "Constructor called" << endl; }
    ~Person() { cout << "Destructor called" << endl; }
};
/*
----------------------------------------
6. Access Specifiers
----------------------------------------
- public: Accessible from anywhere
- private: Accessible only within the class
- protected: Accessible within the class and derived classes

----------------------------------------
7. Friend Function
----------------------------------------
A friend function can access private and protected members of a class.

Example:
*/
class Box {
private:
    int width;
public:
    Box() : width(0) {}
    friend void setWidth(Box&, int);
};

void setWidth(Box& b, int w) {
    b.width = w;
}
/*
----------------------------------------
8. Static Members
----------------------------------------
Static data members are shared by all objects of the class.

Example:
*/
class Counter {
public:
    static int count;
    Counter() { count++; }
};
int Counter::count = 0;
/*
----------------------------------------
9. Operator Overloading
----------------------------------------
You can redefine the way operators work for user-defined types.

Example:
*/
class Complex {
public:
    int real, imag;
    Complex(int r=0, int i=0) : real(r), imag(i) {}
    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }
};
/*
----------------------------------------
10. 'this' Pointer
----------------------------------------
'this' is a pointer to the current object.

Example:
*/
class Demo {
    int x;
public:
    void setX(int x) { this->x = x; }
};
/*
----------------------------------------
11. Dynamic Memory Allocation
----------------------------------------
Objects can be created dynamically using 'new' and destroyed using 'delete'.

Example:
*/
class Student {
public:
    string name;
    Student(string n) : name(n) {}
};

void dynamicExample() {
    Student* s = new Student("Alice");
    cout << s->name << endl;
    delete s;
}
/*
----------------------------------------
12. Namespaces
----------------------------------------
Namespaces prevent name conflicts.

Example:
*/
namespace First {
    void func() { cout << "First namespace" << endl; }
}
namespace Second {
    void func() { cout << "Second namespace" << endl; }
}
/*
----------------------------------------
13. Templates (Generic Programming)
----------------------------------------
Templates allow writing generic classes and functions.

Example:
*/
template <typename T>
T add(T a, T b) {
    return a + b;
}
/*
----------------------------------------
14. Example: All Concepts Together
----------------------------------------
*/
class Vehicle {
protected:
    string brand;
public:
    Vehicle(string b) : brand(b) {}
    virtual void honk() { cout << brand << " goes beep!" << endl; }
};

class Car : public Vehicle {
    int year;
public:
    Car(string b, int y) : Vehicle(b), year(y) {}
    void honk() override { cout << brand << " car from " << year << " goes vroom!" << endl; }
};

void oopsDemo() {
    EncapsulatedStudent s;
    s.setName("John");
    s.setAge(20);
    cout << s.getName() << " is " << s.getAge() << " years old." << endl;

    Dog d;
    d.eat();
    d.bark();

    Print p;
    p.show(5);
    p.show(3.14);
    p.show("Hello");

    Base* bptr = new Derived();
    bptr->display();
    delete bptr;

    Circle c;
    Rectangle r;
    AbstractShape* shape;
    shape = &c; shape->draw();
    shape = &r; shape->draw();

    Person p1;

    Box box;
    setWidth(box, 10);

    Counter c1, c2;
    cout << "Counter: " << Counter::count << endl;

    Complex a(1,2), b2(3,4);
    Complex c3 = a + b2;
    cout << "Complex sum: " << c3.real << " + " << c3.imag << "i" << endl;

    Demo demo;
    demo.setX(42);

    dynamicExample();

    First::func();
    Second::func();

    cout << "Sum: " << add<int>(2,3) << endl;

    Car myCar("Toyota", 2020);
    myCar.honk();
}
/*
----------------------------------------
Summary:
OOP in C++ is a vast topic, covering encapsulation, inheritance, polymorphism, abstraction, constructors/destructors, access specifiers, friend functions, static members, operator overloading, 'this' pointer, dynamic memory, namespaces, templates, and more. Mastery of these concepts enables you to write robust, reusable, and maintainable code.
*/
