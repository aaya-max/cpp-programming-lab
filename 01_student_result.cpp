#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks[5];

public:
    void inputDetails() {
        cout << "Enter roll number: ";
        cin >> rollNumber;

        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter marks in 5 subjects (out of 100): ";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
            if (marks[i] < 0 || marks[i] > 100) {
                cout << "Invalid marks. Enter marks between 0 and 100: ";
                cin >> marks[i];
                while (marks[i] < 0 || marks[i] > 100) {
                    cout << "Please enter a valid mark: ";
                    cin >> marks[i];
                }
            }
        }
    }

    float calculateTotal() const {
        float total = 0;
        for (int i = 0; i < 5; i++) {
            total += marks[i];
        }
        return total;
    }

    float calculatePercentage() const {
        return calculateTotal() / 5.0f;
    }

    void displayResult() const {
        float percentage = calculatePercentage();

        cout << "\n----- Student Result -----\n";
        cout << "Roll Number: " << rollNumber << '\n';
        cout << "Name: " << name << '\n';
        cout << fixed << setprecision(2);
        cout << "Total Marks: " << calculateTotal() << " / 500\n";
        cout << "Percentage: " << percentage << "%\n";

        if (percentage >= 40) {
            cout << "Result: Pass\n";
        } else {
            cout << "Result: Fail\n";
        }
    }
};

int main() {
    Student student;
    student.inputDetails();
    student.displayResult();
    return 0;
}
