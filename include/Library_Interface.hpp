#ifndef LIBRARY_INTERFACE_H
#define LIBRARY_INTERFACE_H

#include "Constant_Headers.hpp"
#include "Storage_Interface.hpp"
#include "Book_Interface.hpp"

class Library_Interface{
    private:
    std::vector<Book_Interface> books;
    Storage_Interface& storage;

public:
    Library_Interface(Storage_Interface& storage);

    void addBook(const Book_Interface& book);
    void removeBook(const std::string& title);
    void removeAllBooks();
    void searchBook(const std::string& query) const;
    void borrowBook(const std::string& title);
    void returnBook(const std::string& title);
    void listBooks() const;
};

#endif