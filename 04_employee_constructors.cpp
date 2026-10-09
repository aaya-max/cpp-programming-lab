#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int employeeId;
    string name;
    double basicSalary;
    double bonus;

public:
    Employee() {
        employeeId = 0;
        name = "Unknown";
        basicSalary = 0;
        bonus = 0;
        cout << "Default constructor called\n";
    }

    Employee(int id, string empName, double salary, double empBonus) {
        employeeId = id;
        name = empName;
        basicSalary = salary;
        bonus = empBonus;
        cout << "Parameterized constructor called\n";
    }

    double calculateTotalSalary() const {
        return basicSalary + bonus;
    }

    void display() const {
        cout << "Employee ID: " << employeeId << '\n';
        cout << "Name: " << name << '\n';
        cout << "Basic Salary: " << basicSalary << '\n';
        cout << "Bonus: " << bonus << '\n';
        cout << "Total Salary: " << calculateTotalSalary() << "\n\n";
    }
};

int main() {
    Employee emp1;
    emp1.display();

    Employee emp2(101, "John Doe", 50000, 10000);
    emp2.display();

    return 0;
}
