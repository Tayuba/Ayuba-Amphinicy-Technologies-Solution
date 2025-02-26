/**
 * @file main.cpp
 * @brief Entry point for the Library Management System.
 * 
 * This file contains the main function that runs the Library Management System.
 * It provides an interactive menu for users to manage books in the library.
 * 
 * Data Structure Used: std::vector<Book_Interface>
 * - Used to store book objects dynamically.
 * - Efficient retrieval and updates.
 * 
 * @author Ayuba Tahiru
 * @date 2025-02-25
*/


#include "Interfaces.hpp"


/**
 * @brief Main function that drives the Library Management System.
 * 
 * Provides an interactive menu where users can:
 * 1- Add books
 * 2- Remove books
 * 3- Remove all books
 * 4- Search for books
 * 5- Borrow books
 * 6- Return books
 * 7- List all books
 * 8- Exit the system
 * 
 * Handles user input validation to prevent incorrect entries.
 * 
 * @return int Returns 0 upon successful execution.
*/
int main() {
    Storage_Interface storage("data/book_DB.txt");
    Library_Interface library(storage);

    int choice, year;
    std::string title, author;

    do {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add Book\n2. Remove Book\n3. Remove All Books\n4. Search Book\n5. Borrow Book\n6. Return Book\n7. List Books\n8. Exit\n";
        std::cout << "Enter choice: ";
      
        if (!(std::cin >> choice)) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 8.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                std::cout << "Enter author name: ";
                std::getline(std::cin, author);
                std::cout << "Enter publication year: ";
                std::cin >> year;
                std::cin.ignore();
                library.addBook(Book_Interface(title, author, year));
                break;
            case 2:
                std::cout << "Enter book title to remove: ";
                std::getline(std::cin, title);
                library.removeBook(title);
                break;
            case 3:
                library.removeAllBooks();
                break;
            case 4:
                std::cout << "Enter title, author, year or row number to search: ";
                std::getline(std::cin, title);
                library.searchBook(title);
                break;
            case 5:
                std::cout << "Enter book title to borrow: ";
                std::getline(std::cin, title);
                library.borrowBook(title);
                break;
            case 6:
                std::cout << "Enter book title to return: ";
                std::getline(std::cin, title);
                library.returnBook(title);
                break;
            case 7:
                library.listBooks();
                break;
            case 8:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
