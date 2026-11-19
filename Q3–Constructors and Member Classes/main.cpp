
#include <iostream>
#include <string>
using namespace std;

// Member class: Address
class Address {
private:
    string city;
    int pin;

public:
    Address(string c, int p) : city(c), pin(p) {
        cout << "Address Constructor\n";
    }

    string str() const {
        return city + "-" + to_string(pin);
    }

    ~Address() {
        cout << "Address Destructor\n";
    }
};

// Member class: Course
class Course {
private:
    string courseName;

public:
    Course(string c) : courseName(c) {
        cout << "Course Constructor\n";
    }

    ~Course() {
        cout << "Course Destructor\n";
    }
};

// Base class
class Person {
protected:
    string name;
    int age;
    Address home;

public:
    Person(string n, int a, string city, int pin)
        : name(n), age(a), home(city, pin) {
        cout << "Person Constructor\n";
    }

    ~Person() {
        cout << "Person Destructor\n";
    }
};

// Student inherits Person virtually
class Student : virtual public Person {
protected:
    long long regNo;
    Course course;

public:
    Student(string n, int a, string city, int pin,
            long long r, string c)
        : Person(n, a, city, pin),
          regNo(r), course(c) {
        cout << "Student Constructor\n";
    }

    void displayStudent() const {
        cout << regNo << " " << name << " (" << age
             << ") " << home.str() << endl;
    }

    ~Student() {
        cout << "Student Destructor\n";
    }
};

// Staff inherits Person virtually
class Staff : virtual public Person {
protected:
    string department;

public:
    Staff(string n, int a, string city, int pin,
          string d)
        : Person(n, a, city, pin), department(d) {
        cout << "Staff Constructor\n";
    }

    ~Staff() {
        cout << "Staff Destructor\n";
    }
};

// TeachingAssistant inherits Student and Staff
class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int a, string city, int pin,
                      long long r, string c, string d)
        : Person(n, a, city, pin),
          Student(n, a, city, pin, r, c),
          Staff(n, a, city, pin, d) {
        cout << "TeachingAssistant Constructor\n";
    }

    ~TeachingAssistant() {
        cout << "TeachingAssistant Destructor\n";
    }
};

int main() {

    cout << "\n--- STUDENT OBJECT ---\n";
    {
        Student s("Kavya", 19, "Salem", 636001,
                  192311001, "CSE");
        s.displayStudent();
    }

    cout << "\n--- STAFF OBJECT ---\n";
    {
        Staff st("Ravi", 40, "Chennai", 600001,
                 "Computer Science");
    }

    cout << "\n--- TEACHING ASSISTANT OBJECT ---\n";
    {
        TeachingAssistant ta(
            "Anu", 25, "Tirupati", 517501,
            192311002, "CSE", "AI Department"
        );
    }

    cout << "\nSize of TeachingAssistant: "
         << sizeof(TeachingAssistant) << " bytes\n";

    return 0;
}
