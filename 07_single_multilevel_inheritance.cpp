#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string address;

public:
    Person(string personName, int personAge, string personAddress)
        : name(personName), age(personAge), address(personAddress) {}

    void displayPerson() const {
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
        cout << "Address: " << address << '\n';
    }
};

// Single inheritance: Student inherits from Person.
class Student : public Person {
protected:
    int rollNumber;
    float marks;

public:
    Student(string studentName, int studentAge, string studentAddress,
            int roll, float studentMarks)
        : Person(studentName, studentAge, studentAddress),
          rollNumber(roll), marks(studentMarks) {}

    void displayStudent() const {
        displayPerson();
        cout << "Roll Number: " << rollNumber << '\n';
        cout << "Marks: " << marks << '\n';
    }
};

// Multilevel inheritance: GraduateStudent inherits from Student,
// and Student inherits from Person.
class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(string studentName, int studentAge, string studentAddress,
                    int roll, float studentMarks, string topic)
        : Student(studentName, studentAge, studentAddress, roll, studentMarks),
          researchTopic(topic) {}

    void displayGraduateStudent() const {
        displayStudent();
        cout << "Research Topic: " << researchTopic << '\n';
    }
};

int main() {
    cout << "----- Single Inheritance: Student -----\n";
    Student student("John Doe", 20, "123 Main St", 101, 85.5f);
    student.displayStudent();

    cout << "\n----- Multilevel Inheritance: Graduate Student -----\n";
    GraduateStudent graduate("Asha Sharma", 22, "Pune, India",
                             202, 91.0f, "Artificial Intelligence");
    graduate.displayGraduateStudent();

    return 0;
}
