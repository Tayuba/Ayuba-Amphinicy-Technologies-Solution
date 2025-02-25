#include "../include/Book_Interface.hpp"


Book_Interface::Book_Interface(const std::string& title, const std::string& author, int year)
    : title(title), author(author), year(year), isBorrowed(false) {}

std::string Book_Interface::getTitle() const {
    return title;
}

std::string Book_Interface::getAuthor() const {
    return author;
}

bool Book_Interface::getBorrowedStatus() const {
    return isBorrowed;
}

void Book_Interface::borrowBook() {
    isBorrowed = true;
}

void Book_Interface::returnBook() {
    isBorrowed = false;
}

int Book_Interface::getYear() const {
    return year;
}

std::string Book_Interface::toString() const {
    return title + "," + author + "," + std::to_string(year) + "," + (isBorrowed ? "1" : "0");
}