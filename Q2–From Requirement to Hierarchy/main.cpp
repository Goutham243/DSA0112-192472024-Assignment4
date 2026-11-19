
#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int id;
    string phone;

public:
    Person(string n, int i, string p)
        : name(n), id(i), phone(p) {
        cout << "Person ";
    }

    void displayPerson() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Phone: " << phone << endl;
    }
};

// Student inherits Person virtually
class Student : virtual public Person {
protected:
    string programme;
    double cgpa;

public:
    Student(string n, int i, string p,
            string prog, double c)
        : Person(n, i, p),
          programme(prog), cgpa(c) {
        cout << "Student\n";
    }

    void displayStudent() const {
        cout << "Programme: " << programme << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

// Staff inherits Person virtually
class Staff : virtual public Person {
protected:
    string department;
    double salary;

public:
    Staff(string n, int i, string p,
          string dept, double s)
        : Person(n, i, p),
          department(dept), salary(s) {
        cout << "Staff ";
    }

    void displayStaff() const {
        cout << "Department: " << department << endl;
        cout << "Salary: Rs. " << salary << endl;
    }
};

// TeachingAssistant inherits Student and Staff
class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p,
                      string prog, double c,
                      string dept, double s)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          Staff(n, i, p, dept, s) {
        cout << "TA ";
    }

    void display() const {
        displayPerson();
        displayStudent();
        displayStaff();
    }
};

// ResearchScholar is a specialized Student
class ResearchScholar : public Student {
private:
    double fellowship;

public:
    ResearchScholar(string n, int i, string p,
                    string prog, double c, double f)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          fellowship(f) {}

    void displayFellowship() const {
        cout << "Fellowship: Rs. " << fellowship << endl;
    }
};

int main() {
    TeachingAssistant ta(
        "Kavya", 101, "9876543210",
        "CSE", 9.1, "AI Department", 35000
    );

    cout << endl << "\nTEACHING ASSISTANT DETAILS\n";
    ta.display();

    cout << "\nRESEARCH SCHOLAR DETAILS\n";

    ResearchScholar rs(
        "Arun", 102, "9123456780",
        "CSE", 9.4, 25000
    );

    rs.displayPerson();
    rs.displayStudent();
    rs.displayFellowship();

    return 0;
}
