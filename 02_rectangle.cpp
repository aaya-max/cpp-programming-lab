#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float breadth;

public:
    void setDimensions(float l, float b) {
        length = l;
        breadth = b;
    }

    float calculateArea() const {
        return length * breadth;
    }

    float calculatePerimeter() const {
        return 2 * (length + breadth);
    }

    void display() const {
        cout << "Length: " << length << '\n';
        cout << "Breadth: " << breadth << '\n';
        cout << "Area: " << calculateArea() << '\n';
        cout << "Perimeter: " << calculatePerimeter() << '\n';
    }
};

int main() {
    Rectangle rect;
    float length, breadth;

    cout << "Enter length and breadth: ";
    cin >> length >> breadth;

    if (length <= 0 || breadth <= 0) {
        cout << "Length and breadth must be positive.\n";
        return 1;
    }

    rect.setDimensions(length, breadth);
    rect.display();

    return 0;
}
