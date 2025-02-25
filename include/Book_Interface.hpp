#ifndef BOOK_INTERFACE_H
#define BOOK_INTERFACE_H

#include "Constant_Headers.hpp"

class Book_Interface{
    private:
    std::string title;
    std::string author;
    int year;
    bool isBorrowed;

public:
    // Constructor
    Book_Interface(const std::string& title, const std::string& author, int year);

    // Getters
    std::string getTitle() const;
    std::string getAuthor() const;

    bool getBorrowedStatus() const;

    int getYear() const;

    void borrowBook();
    void returnBook();

    std::string toString() const;
};

#endif