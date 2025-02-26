/**
 * @file Library_Interface.hpp
 * @brief Interface for managing library operations.
 * 
 * This file defines the Library_Interface class, which provides methods for managing 
 * books within a library management system.
 * 
 * 
 * @author Ayuba Tahiru
 * @date 2025-02-25
 * 
 * @include provides methods to add, remove, search, borrow, list and return books
 * @note This class interate with Storage_Interface class
*/

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
    /**
     * @brief Constructs a Library_Interface object.
     * @param storage Reference to a Storage_Interface object for book storage management.
    */
    Library_Interface(Storage_Interface& storage);

    /**
     * @brief Adds a new book to the library.
     * @param book The book to be added.
    */
    void addBook(const Book_Interface& book);

    /**
     * @brief Removes a book from the library by title.
     * @param title The title of the book to be removed.
    */
    void removeBook(const std::string& title);

    /**
     * @brief Removes all books from the library while keeping column headers in storage.
    */
    void removeAllBooks();

    /**
     * @brief Searches for a book by title, author, year, or row number.
     * @param query The search term (case-insensitive).
    */
    void searchBook(const std::string& query) const;

    /**
     * @brief Borrows a book from the library.
     * @param title The title of the book to be borrowed.
    */
    void borrowBook(const std::string& title);

    /**
     * @brief Returns a borrowed book to the library.
     * @param title The title of the book to be returned.
    */
    void returnBook(const std::string& title);

    /**
     * @brief Lists all books currently in the library.
    */
    void listBooks() const;
};

#endif