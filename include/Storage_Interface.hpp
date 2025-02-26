/**
 * @file Storage_Interface.hpp
 * @brief Interface for handling persistent storage of books.
 * 
 * This file defines the Storage_Interface class, responsible for reading and writing 
 * book data to and from a file. It ensures data persistence for the library system.
 * 
 * Data Structure Used: std::vector<Book_Interface>
 * - Books are stored dynamically in a vector and read/written to a file.
 * - File storage is handled using std::ifstream and std::ofstream.
 * 
 * @author Ayuba Tahiru
 * @date 2025-02-25
*/

#ifndef STORAGE_INTERFACE_H
#define STORAGE_INTERFACE_H

#include "Constant_Headers.hpp"
#include "Book_Interface.hpp"

class Storage_Interface {
    private:
        std::string storageFile;
    
    public:
    /**
     * @brief Constructs a Storage_Interface object with the specified file.
     * 
     * @param filename The name of the file used for storing book data.
    */
    Storage_Interface(const std::string& filename);

    /**
    * @brief Loads books from the storage file into a vector.
    * 
    * Reads book data from the file, parses it, and constructs a 
    * vector of Book_Interface objects.
    * 
    * Complexity: O(n).
    * 
    * @return std::vector<Book_Interface> A list of books retrieved from storage.
    */
    std::vector<Book_Interface> loadBooks();

    /**
     * @brief Saves a collection of books to the storage file.
     * 
     * Writes the book data to the file in a structured format to 
     * ensure persistence.
     * 
     * Complexity: O(n)d.
     * 
     * @param books A vector containing all books to be saved.
    */ 
    void saveBooks(const std::vector<Book_Interface>& books);
};

#endif