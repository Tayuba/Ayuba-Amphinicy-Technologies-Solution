/**
 * @file Storage_Interface.cpp
 * @brief Implementation of the Storage_Interface class.
 * 
 * This file implements methods for reading and writing book data to a file.
 * It ensures that the library system's books are persistently stored between sessions.
 * 
 * Data Structure Used: std::vector<Book_Interface>
 * - Uses dynamic storage in a vector for easy manipulation.
 * - Reads and writes data using std::ifstream and std::ofstream.
 * 
*/


#include "../include/Storage_Interface.hpp"


/**
 * @brief Constructs a Storage_Interface object with a specified storage file.
 * 
 * @param filename The name of the file used for storing book data.
*/
Storage_Interface::Storage_Interface(const std::string& filename) : storageFile(filename) {}


/**
 * @brief Loads books from the storage file into a vector.
 * 
 * Reads book data from the file, parses it, and constructs a vector of Book_Interface objects.
 * 
 * Complexity: O(n).
 * 
 * @return std::vector<Book_Interface> A list of books retrieved from storage.
*/
std::vector<Book_Interface> Storage_Interface::loadBooks() {
    std::vector<Book_Interface> books;
    std::ifstream file(storageFile);
    if (!file) {
        std::cerr << "Error opening storage file: " << storageFile << std::endl;
        return books;
    }

    std::string line;
    bool isFirstLine = true;

    while (std::getline(file, line)) {
        if (isFirstLine) {  
            isFirstLine = false;  
            continue;
        }

        std::stringstream ss(line);
        std::string title, author, status, yearStr;
     
        std::getline(ss, title, ',');
        std::getline(ss, author, ',');
        std::getline(ss, yearStr, ',');
        std::getline(ss, status, ',');

        int year = std::stoi(yearStr);
        Book_Interface book(title, author, year);
        if (status == "1") {
            book.borrowBook();
        }

        books.push_back(book);
    }

    file.close();
    return books;
}


/**
 * @brief Saves a collection of books to the storage file.
 * 
 * Writes the book data to the file in a structured format to ensure persistence.
 * 
 * Complexity: O(n).
 * 
 * @param books A vector containing all books to be saved.
*/
void Storage_Interface::saveBooks(const std::vector<Book_Interface>& books) {
    std::ofstream file(storageFile, std::ios::trunc);
    if (!file) {
        std::cerr << "Error opening storage file for writing: " << storageFile << std::endl;
        return;
    }

    file << "Title,Author,Year,Borrowed\n"; 

    for (const auto& book : books) {
        file << book.toString() << "\n";
    }

    file.close();
}
