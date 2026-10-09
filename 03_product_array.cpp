#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Product {
private:
    int productId;
    string productName;
    double price;
    int quantitySold;

public:
    void inputDetails() {
        cout << "Enter product ID: ";
        cin >> productId;

        cin.ignore();
        cout << "Enter product name: ";
        getline(cin, productName);

        cout << "Enter price: ";
        cin >> price;
        cout << "Enter total quantity sold: ";
        cin >> quantitySold;
    }

    double calculateBill() const {
        return price * quantitySold;
    }

    void display() const {
        cout << "\nProduct ID: " << productId << '\n';
        cout << "Product Name: " << productName << '\n';
        cout << fixed << setprecision(2);
        cout << "Price: " << price << '\n';
        cout << "Total Quantity Sold: " << quantitySold << '\n';
        cout << "Total Bill: " << calculateBill() << '\n';
    }
};

int main() {
    const int SIZE = 2;
    Product products[SIZE];
    double grandTotal = 0;

    cout << "Enter details for " << SIZE << " products:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nProduct " << i + 1 << '\n';
        products[i].inputDetails();
    }

    cout << "\n----- All Products Details -----\n";
    for (int i = 0; i < SIZE; i++) {
        products[i].display();
        grandTotal += products[i].calculateBill();
    }

    cout << fixed << setprecision(2);
    cout << "\nGrand Total Bill: " << grandTotal << '\n';
    return 0;
}
