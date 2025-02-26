/**
 * @file Book_Interface.cpp
 * @brief Implementation of the Book_Interface class.
 * 
 * This file implements the Book_Interface class, defining methods for retrieving 
 * book details and managing borrowing status.
 * 
 * Data Structure Used: Plain class with member variables.
 * - O(1) access time for all operations since data is stored in class members.
 * 
*/


#include "../include/Book_Interface.hpp"

/**
 * @brief Constructs a new Book_Interface object.
 * 
 * @param title The title of the book.
 * @param author The author's name.
 * @param year The publication year.
*/
Book_Interface::Book_Interface(const std::string& title, const std::string& author, int year)
    : title(title), author(author), year(year), isBorrowed(false) {}


/**
 * @brief Retrieves the title of the book.
 * @return std::string The book's title.
*/    
std::string Book_Interface::getTitle() const {
    return title;
}


/**
 * @brief Retrieves the author's name.
 * @return std::string The book's author.
*/
std::string Book_Interface::getAuthor() const {
    return author;
}


/**
 * @brief Checks if the book is currently borrowed.
 * @return true If the book is borrowed.
 * @return false If the book is available.
*/
bool Book_Interface::getBorrowedStatus() const {
    return isBorrowed;
}


/**
 * @brief Marks the book as borrowed.
 * 
 * If the book is already borrowed, a warning message is displayed.
*/
void Book_Interface::borrowBook() {
    isBorrowed = true;
}


/**
 * @brief Marks the book as returned.
 * 
 * If the book was not borrowed, a warning message is displayed.
*/
void Book_Interface::returnBook() {
    isBorrowed = false;
}


/**
 * @brief Retrieves the publication year of the book.
 * @return int The book's publication year.
*/
int Book_Interface::getYear() const {
    return year;
}


/**
 * @brief Converts book details into a formatted string representation.
 * @return std::string A formatted string containing book details.
 */ 
std::string Book_Interface::toString() const {
    return title + "," + author + "," + std::to_string(year) + "," + (isBorrowed ? "1" : "0");
}