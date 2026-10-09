#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    double price;
    static int bookCount;

public:
    Book(int id, string bookTitle, string bookAuthor, double bookPrice)
        : bookId(id), title(bookTitle), author(bookAuthor), price(bookPrice) {
        bookCount++;
        cout << "Book created. Total books: " << bookCount << '\n';
    }

    Book(const Book& other)
        : bookId(other.bookId), title(other.title),
          author(other.author), price(other.price) {
        bookCount++;
        cout << "Book copied. Total books: " << bookCount << '\n';
    }

    ~Book() {
        bookCount--;
        cout << "Book destroyed. Total books: " << bookCount << '\n';
    }

    void display() const {
        cout << "Book ID: " << bookId << '\n';
        cout << "Title: " << title << '\n';
        cout << "Author: " << author << '\n';
        cout << "Price: " << price << '\n';
    }

    static int getBookCount() {
        return bookCount;
    }
};

int Book::bookCount = 0;

int main() {
    {
        Book b1(101, "C++ Programming", "Bjarne Stroustrup", 4500);
        b1.display();

        Book b2 = b1;
        b2.display();

        cout << "Total books: " << Book::getBookCount() << '\n';
    }

    cout << "Books remaining: " << Book::getBookCount() << '\n';
    return 0;
}
