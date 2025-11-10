#include <iostream>
#include <cstring>
using namespace std;
class Book {
private:
    char *title;
    char *author;
    char ISBN[20];
    char *review;
public:
    Book(const char *t, const char *a, const char *i, const char *r) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        author = new char[strlen(a) + 1];
        strcpy(author, a);
        strcpy(ISBN, i);
        review = new char[strlen(r) + 1];
        strcpy(review, r);
    }
    Book(const Book &b) {
        title = new char[strlen(b.title) + 1];
        strcpy(title, b.title);
        author = new char[strlen(b.author) + 1];
        strcpy(author, b.author);
        strcpy(ISBN, b.ISBN);
        review = new char[strlen(b.review) + 1];
        strcpy(review, b.review);
        cout << "Deep copy constructor called.\n";
    }
    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Review: " << review << endl << endl;
    }
    void updateReview(const char *newReview) {
        delete[] review;
        review = new char[strlen(newReview) + 1];
        strcpy(review, newReview);
    }
            ~Book() {
        delete[] title;
        delete[] author;
        delete[] review;
        cout << "Memory released for book: " << ISBN << endl;
    }
};
int main() {
    cout << "=== Original Book ===" << endl;
    Book b1("C++ Programming", "Bjarne Stroustrup", "12345", "Excellent book for beginners.");
    b1.display();
    cout << "=== Copying Book using Copy Constructor ===" << endl;
    Book b2 = b1; 
    b2.display();
    cout << "Updating review in copied book..." << endl;
    b2.updateReview("Very helpful and detailed.");
    cout << "\n=== After modifying copy ===" << endl;
    cout << "Original Book Review:" << endl;
    b1.display();
    cout << "Copied Book Review:" << endl;
    b2.display();
    return 0;
}

