#include <iostream>
#include <string>
using namespace std;

class Number {
private:
    int value;
    static int objectCount;

public:
    Number(int v) : value(v) {
        objectCount++;
    }

    static int getObjectCount() {
        return objectCount;
    }

    friend void compareValues(const Number& first, const Number& second);
};

int Number::objectCount = 0;

void compareValues(const Number& first, const Number& second) {
    if (first.value > second.value) {
        cout << "First number is greater.\n";
    } else if (second.value > first.value) {
        cout << "Second number is greater.\n";
    } else {
        cout << "Both numbers are equal.\n";
    }
}

class FriendExample {
private:
    string password;
    int secretNumber;

public:
    FriendExample(string pass, int number)
        : password(pass), secretNumber(number) {}

    friend void showPrivateDetails(const FriendExample& item);
};

void showPrivateDetails(const FriendExample& item) {
    cout << "Password: " << item.password << '\n';
    cout << "Secret Number: " << item.secretNumber << '\n';
}

int main() {
    Number n1(25);
    Number n2(40);

    cout << "----- Comparing Numbers -----\n";
    compareValues(n1, n2);
    cout << "Number of objects: " << Number::getObjectCount() << '\n';

    FriendExample example("samplePass123", 999);
    cout << "\n----- Friend Function -----\n";
    showPrivateDetails(example);

    return 0;
}
