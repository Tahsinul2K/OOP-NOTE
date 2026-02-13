#include <iostream>
#include <string>
using namespace std;

class Book
{
    string title;
    string author;
    int ratingCount;
    double avgRating;

public:
    Book()
    {
        title = "";
        author = "";
        ratingCount = 0;
        avgRating = 0.0;
    }
    Book(string title, string author)
    {
        this->title = title;
        this->author = author;
        ratingCount = 0;
        avgRating = 0.0;
    }
    void addRating(int rating)
    {
        double totalRating = avgRating * ratingCount;
        totalRating += rating;
        ratingCount++;
        avgRating = totalRating / ratingCount;
        return;
    }
    double getAverageRating()
    {
        return avgRating;
    }
    void display()
    {
        cout << "Title: " << title << ", Author: " << author
             << ", Average Rating: " << avgRating << " (" << ratingCount << " ratings)" << endl;
    }
    bool operator==(const Book &b)
    {
        return (title == b.title) && (author == b.author);
    }
};

class Library
{
    Book *books;
    int totalBooks;
    int maxBooks;

public:
    Library()
    {
        maxBooks = 0;
        totalBooks = 0;
        books = nullptr;
    }
    Library(int MaxBooks)
    {
        maxBooks = MaxBooks;
        totalBooks = 0;
        books = new Book[maxBooks];
    }
    Library(int maxBooks, Book *books, int totalBooks)
    {
        this->maxBooks = maxBooks;
        this->books = books;
        this->totalBooks = totalBooks;
    }

    Library(Library &x)
    {
        this->books = x.books;
        this->totalBooks = x.totalBooks;
        this->maxBooks = x.maxBooks;
    }
    ~Library()
    {
        free(books);
        totalBooks = 0;
        maxBooks = 0;
    }
    void addBook(Book b)
    {
        if (totalBooks < maxBooks)
        {
            books[totalBooks++] = b;
            return;
        }
        else
        {
            cout << "Library is full. Cannot add more books." << endl;
            return;
        }
    }
    void removeBook(Book b)
    {
        for (int i = 0; i < totalBooks; i++)
        {
            if (books[i] == b)
            {
                for (int j = i + 1; j < totalBooks; j++)
                {
                    books[j - 1] = books[j];
                }
            }
        }
    }

    void rateBook(string title, string author, int rating)
    {
        for (int i = 0; i < totalBooks; i++)
        {
            if (books[i] == Book(title, author))
            {
                books[i].addRating(rating);
                return;
            }
        }
    }

    void showBooks()
    {
        for (int i = 0; i < totalBooks; i++)
        {
            books[i].display();
        }
    }

    Book bestRatedBook()
    {
        int idx = 0;
        double maxRating = -1;
        for (int i = 0; i < totalBooks; i++)
        {
            if (books[i].getAverageRating() > maxRating)
            {
                idx = i;
                maxRating = books[i].getAverageRating();
            }
        }
        return books[idx];
    }
};

int main()
{
    Library lib1(5);
    Book b1("The Great Gatsby", "F. Scott Fitzgerald");
    Book b2("To Kill a Mockingbird", "Harper Lee");
    Book b3("1984", "George Orwell");
    Book b4("War and Peace", "Leo Tolstoy");
    Book b5("The Kite Runner", "Khaled Hosseini");
    Book b6("A Tale of Two Cities", "Charles Dickens");
    lib1.addBook(b1);
    lib1.addBook(b2);
    lib1.addBook(b3);
    lib1.addBook(b4);
    lib1.addBook(b5);
    lib1.addBook(b6);
    lib1.rateBook("The Great Gatsby", "F. Scott Fitzgerald", 5);
    lib1.rateBook("The Great Gatsby", "F. Scott Fitzgerald", 4);
    lib1.rateBook("To Kill a Mockingbird", "Harper Lee", 5);
    lib1.rateBook("1984", "George Orwell", 4);
    lib1.rateBook("1984", "George Orwell", 5);
    lib1.rateBook("1984", "George Orwell", 5);
    lib1.rateBook("War and Peace", "Leo Tolstoy", 3);
    lib1.rateBook("War and Peace", "Leo Tolstoy", 4);
    lib1.rateBook("The Kite Runner", "Khaled Hosseini", 5);
    lib1.rateBook("The Kite Runner", "Khaled Hosseini", 4);
    lib1.rateBook("The Kite Runner", "Khaled Hosseini", 5);
    cout << "\nLibrary 1 Books and Ratings:\n";
    lib1.showBooks();
    cout << "\nBest Rated Book in Library 1:\n";
    lib1.bestRatedBook().display();
    cout << endl;
    Library lib2(lib1);
    lib2.removeBook(b2);
    lib2.addBook(b6);
    cout << "\nLibrary 2 Books and Ratings:\n";
    lib2.showBooks();

    cout << "\nBest Rated Book in Library 1:\n";
    lib1.bestRatedBook().display();
    cout << "\nBest Rated Book in Library 2:\n";
    lib2.bestRatedBook().display();
    return 0;
}