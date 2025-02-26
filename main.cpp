#include "Interfaces.hpp"

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
