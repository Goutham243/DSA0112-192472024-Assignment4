
#include <iostream>
using namespace std;

class Account {
public:
    double rate() const {
        return 3.5;
    }

    ~Account() {
        cout << "Account Destructor\n";
    }
};

class SeniorAccount : public Account {
private:
    double* history;

public:
    SeniorAccount() {
        history = new double[100];
        cout << "SeniorAccount Constructor\n";
    }

    double rate() const {
        return 4.0;
    }

    ~SeniorAccount() {
        cout << "SeniorAccount Destructor\n";
        delete[] history;
    }
};

int main() {
    Account* accounts[2] = {
        new Account,
        new SeniorAccount
    };

    cout << "Interest Rates:\n";

    for (Account* a : accounts) {
        cout << a->rate() << endl;
    }

    cout << "\nDeleting Accounts:\n";

    for (Account* a : accounts) {
        delete a;
    }

    Account copy = SeniorAccount();

    return 0;
}
