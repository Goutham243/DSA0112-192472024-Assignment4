
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// Base class
class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual ~Account() {
        cout << "Account Destructor\n";
    }
};

// Derived class
class SeniorAccount : public Account {
private:
    double* history;

public:
    SeniorAccount() : history(new double[100]) {
        cout << "SeniorAccount Constructor\n";
    }

    double rate() const override {
        return 4.0;
    }

    ~SeniorAccount() override {
        cout << "SeniorAccount Destructor\n";
        delete[] history;
    }
};

int main() {

    vector<unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Account>());
    accounts.push_back(make_unique<SeniorAccount>());

    cout << "\nInterest Rates:\n";

    for (const auto& a : accounts) {
        cout << a->rate() << endl;
    }

    cout << "\nObject Slicing Demonstration:\n";

    SeniorAccount s;
    Account* p = &s;

    Account copy = s;

    cout << p->rate() << " "
         << p->rate() << " "
         << copy.rate() << endl;

    cout << "\nProgram Finished\n";

    return 0;
}
