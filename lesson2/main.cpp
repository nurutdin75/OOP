#include <iostream>

using namespace std;

//TASK 1
class Person
{
public:
    Person(string _name, int _age, char _gender, int _weight):name(_name), age(_age), gender(_gender), weight(_weight){};
    ~Person(){}
    void set_name(string _name) {name = _name;}
    void set_age(int _age) {age = _age;}
    void set_weight(int _weight) {weight = _weight;}
    void print(){cout << name << " " << age << " " << gender << " " << weight << " ";}

private:
    string name;
    int age;
    char gender;
    int weight;

};
class Student : public Person
{
public:
    Student(string _name, int _age, char _gender, int _weight, int _year) : Person(_name, _age, _gender, _weight){ year = _year; ++count;}
    ~Student(){--count;}
    void set_year(int _year) {year = _year;}
    void increase_year(int year) {year++;}
    void print(){
        Person::print();
        cout << year;
    }
    static int getcount(){return count;}
private:
    int year;
    static int count;
};
int Student::count = 0;

//TASK 2
class Fruit
{
public:
    Fruit(string _name, string _color): name(_name), color(_color){};
    ~Fruit(){};
    string getName(){return name;}
    string getColor(){return color;}
private:
    string name;
    string color;
};
class Apple : public Fruit
{
public:
    Apple(string _color):Fruit("apple", _color){};
    Apple(string _name, string _color):Fruit(_name, _color){};
    string getName(){return Fruit::getName();}
    string getColor(){return Fruit::getColor();}
    void print(){cout << "My " << getName() << " is " << getColor() << ".\n";}
};

class Banana : public Fruit
{
public:
    Banana():Fruit("banana", "yellow"){};
    string getName(){return Fruit::getName();}
    string getColor(){return Fruit::getColor();}
    void print(){cout << "My " << getName() << " is " << getColor() << ".\n";}
};
class GrannySmith : public Apple
{
public:
    GrannySmith():Apple("Granny Smith apple", "green"){};
    void print(){Apple::print();};
};


int main()
{
    cout << "Number of students: " << Student::getcount() << endl << endl;
    Student student1("John", 23, 'M', 70, 2010);
    student1.print();
    cout << "\nNumber of students: " << Student::getcount() << endl << endl;
    Student student2("Ann", 22, 'F', 64, 2012);
    student2.print();
    cout << "\nNumber of students: " << Student::getcount() << endl << endl;
    Student student3("Mike", 24, 'M', 73, 2009);
    student3.print();
    cout << "\nNumber of students: " << Student::getcount() << endl << endl;

    Apple a("red");
    a.print();

    Banana b;
    b.print();

    GrannySmith c;
    c.print();

    return 0;
}
