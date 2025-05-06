#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int bookId, string bookTitle, string bookAuthor)
        : id(bookId), title(bookTitle), author(bookAuthor), isIssued(false) {}

    void displayBook() {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author 
             << ", Status: " << (isIssued ? "Issued" : "Available") << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!" << endl;
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }
        for (Book &book : books) {
            book.displayBook();
        }
    }

    void issueBook(int id) {
        for (Book &book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    book.isIssued = true;
                    cout << "Book issued successfully!" << endl;
                } else {
                    cout << "Book is already issued!" << endl;
                }
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void returnBook(int id) {
        for (Book &book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    book.isIssued = false;
                    cout << "Book returned successfully!" << endl;
                } else {
                    cout << "This book was not issued." << endl;
                }
                return;
            }
        }
        cout << "Book not found!" << endl;
    }
};

int main() {
    Library library;
    int choice, id;
    string title, author;

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Issue Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book ID, title, and author: ";
                cin >> id;
                cin.ignore();
                getline(cin, title);
                getline(cin, author);
                library.addBook(id, title, author);
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                cout << "Enter book ID to issue: ";
                cin >> id;
                library.issueBook(id);
                break;
            case 4:
                cout << "Enter book ID to return: ";
                cin >> id;
                library.returnBook(id);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}