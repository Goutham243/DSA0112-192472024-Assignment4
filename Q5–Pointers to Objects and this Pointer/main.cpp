
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;

public:
    Cart& add(string item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            n++;
        }
        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double sum = 0;
        for (int i = 0; i < n; i++)
            sum += prices[i];

        return sum * (100 - discount) / 100;
    }
};

int main() {
    cout << fixed << setprecision(2);

    // (a) Direct access
    Cart c1;
    c1.add("Rice", 60).add("Dal", 120);
    c1.setDiscount(10);

    // (b) Pointer access
    Cart* p = &c1;
    p->add("Oil", 180);

    // (c) Reference access
    Cart& ref = c1;
    ref.add("Milk", 50);

    // (d) Dynamic object using new and delete
    Cart* dynamicCart = new Cart;
    dynamicCart->add("Sugar", 80).add("Tea", 100);
    dynamicCart->setDiscount(5);

    cout << "Cart 1 Total: " << c1.total() << endl;
    cout << "Dynamic Cart Total: " << dynamicCart->total() << endl;

    // Array of pointers to Cart objects
    Cart c2, c3;
    c2.add("Book", 200).add("Pen", 50);
    c3.add("Bag", 500).add("Bottle", 100);

    Cart* carts[] = {&c1, &c2, &c3, dynamicCart};
    int count = sizeof(carts) / sizeof(carts[0]);

    int highestIndex = 0;

    for (int i = 1; i < count; i++) {
        if (carts[i]->total() > carts[highestIndex]->total())
            highestIndex = i;
    }

    cout << "Highest Cart Total: "
         << carts[highestIndex]->total() << endl;

    delete dynamicCart;
    return 0;
}
