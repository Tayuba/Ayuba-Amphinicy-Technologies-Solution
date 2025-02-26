/**
 * @file Book_Interface.hpp
 * @brief Interface for representing a book in the library system.
 * 
 * This file defines the Book_Interface class, which represents an individual book.
 * It provides methods to retrieve book details and manage borrowing status.
 * 
 * Data Structure Used: Plain class with member variables.
 * - Efficient O(1) access to book details.
 * 
 * @author Ayuba Tahiru
 * @date 2025-02-25
*/

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
    /**
     * @class Book_Interface
     * @brief Represents a book in the library system.
     * 
     * This class provides methods to retrieve book details, check borrowing status, 
     * and manage borrowing and returning operations.
    */
    Book_Interface(const std::string& title, const std::string& author, int year);

    /**
     * @brief Retrieves the title of the book.
     * @return std::string The book's title.
    */
    std::string getTitle() const;

    /**
     * @brief Retrieves the author's name.
     * @return std::string The book's author.
    */
    std::string getAuthor() const;

    /**
     * @brief Checks if the book is currently borrowed.
     * @return true If the book is borrowed.
     * @return false If the book is available.
    */
    bool getBorrowedStatus() const;

    /**
     * @brief Retrieves the publication year of the book.
     * @return int The book's publication year.
    */
    int getYear() const;

    /**
     * @brief Marks the book as borrowed.
    */
    void borrowBook();

    /**
     * @brief Marks the book as returned.
    */
    void returnBook();

    /**
     * @brief Converts book details into a string format.
     * @return std::string A formatted string representation of the book.
    */
    std::string toString() const;
};

#endif