
#include <iostream>
#include <string>
using namespace std;

constexpr double DA_RATE = 0.42;

// Base class
class Staff {
protected:
    string name;
    int id;

public:
    Staff(string n, int i) : name(n), id(i) {}

    virtual double pay() const = 0;

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Pay: Rs. " << pay() << endl;
    }

    virtual ~Staff() = default;
};

// Derived class 1
class Professor : public Staff {
private:
    double basic;
    double research;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i), basic(b), research(r) {}

    double pay() const override {
        return basic + basic * DA_RATE + research;
    }
};

// Derived class 2
class LabAssistant : public Staff {
private:
    double basic;

public:
    LabAssistant(string n, int i, double b)
        : Staff(n, i), basic(b) {}

    double pay() const override {
        return basic + basic * DA_RATE;
    }
};

// Derived class 3
class GuestFaculty : public Staff {
private:
    double hours;
    double rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i), hours(h), rate(r) {}

    double pay() const override {
        return hours * rate;
    }
};

int main() {
    Professor p("Ravi", 101, 50000, 10000);
    LabAssistant l("Kiran", 102, 30000);
    GuestFaculty g("Anu", 103, 20, 1000);

    Staff* staff[] = {&p, &l, &g};

    cout << "COLLEGE PAYROLL SYSTEM\n\n";

    for (Staff* s : staff) {
        s->display();
        cout << "-------------------\n";
    }

    return 0;
}
