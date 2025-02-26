/**
 * @file Library_Interface.cpp
 * @brief Implementation of the Library_Interface class.
 * 
 * This file implements the methods for managing books within a library system. 
 * The class interacts with Storage_Interface to persist book data. It provides 
 * functionalities such as adding, removing, searching, borrowing, and returning books.
 * 
 * Data Structure Used: std::vector<Book_Interface> 
 * - Provides dynamic storage of books.
 * - Efficient appends (O(1)) but slow removals (O(n)).
 *
*/

#include "../include/Library_Interface.hpp"


/**
 * @brief Constructs a Library_Interface object and loads books from storage.
 * 
 * Uses a vector for book storage, allowing dynamic resizing.
 * Complexity: O(n) due to file parsing.
 * 
 * @param storage Reference to a Storage_Interface object.
*/
Library_Interface::Library_Interface(Storage_Interface& storage) : storage(storage) {
    books = storage.loadBooks();
}


/**
 * @brief Converts a string to lowercase.
 * 
 * Complexity: O(n).
 * 
 * @param str Input string.
 * @return std::string Lowercase version of input.
*/
std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) {
        return std::tolower(c); 
    }
    );
    return lowerStr;
}


/**
 * @brief Adds a new book to the library.
 * 
 * Uses std::vector::push_back() for insertion.
 * Complexity: O(1) (Amortized constant time for insertion at the end).
 * 
 * @param book The book to be added.
*/
void Library_Interface::addBook(const Book_Interface& book) {
    books.push_back(book);
    storage.saveBooks(books);
    std::cout << "Book added: " << book.getTitle() << std::endl;
}


/**
 * @brief Removes a book from the library by title.
 * 
 * Uses linear search (O(n)) and std::vector::erase() (O(n)).
 * 
 * @param title The title of the book to be removed.
*/
void Library_Interface::removeBook(const std::string& title) {
    std::string lowerTitle = toLowerCase(title);

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (toLowerCase(it->getTitle()) == lowerTitle ) {
            books.erase(it);
            storage.saveBooks(books);
            std::cout << "Book removed: " << title << std::endl;
            return;
        }
    }
    std::cout << "Book not found.\n";
}


/**
 * @brief Removes all books from the library.
 * 
 * Uses std::vector::clear(), which has O(1) complexity.
*/
void Library_Interface::removeAllBooks() {
    books.clear();
    storage.saveBooks(books);
    std::cout << "All books have been removed from the library.\n";
}


/**
 * @brief Searches for a book by title, author, year, or row number.
 * 
 * Uses linear search (O(n)).
 * 
 * @param query The search term.
*/
void Library_Interface::searchBook(const std::string& query) const {
    if (books.empty()) {
        std::cout << "No books available.\n";
        return;
    }

    bool isNumeric = !query.empty() && std::all_of(query.begin(), query.end(), ::isdigit);
    std::string lowerQuery = toLowerCase(query); 
    bool found = false;

    std::cout << "Search Results:\n";

    for (size_t i = 0; i < books.size(); ++i) {
        std::string bookTitle = toLowerCase(books[i].getTitle());
        std::string bookAuthor = toLowerCase(books[i].getAuthor());

        if (bookTitle == lowerQuery || bookAuthor == lowerQuery || 
            (isNumeric && (std::stoi(query) == books[i].getYear() || std::stoi(query) == static_cast<int>(i + 1)))) {
            
            std::cout << "Row: " << i + 1 << " - " 
                      << books[i].getTitle() << " by " 
                      << books[i].getAuthor() << " ("
                      << books[i].getYear() << ")"
                      << (books[i].getBorrowedStatus() ? " [Borrowed]" : "") 
                      << std::endl;

            found = true;
        }
    }

    if (!found) {
        std::cout << "No book found with the given query.\n";
    }
}


/**
 * @brief Borrows a book from the library.
 * 
 * Uses linear search (O(n)) and updates a flag (O(1)).
 * 
 * @param title The title of the book to be borrowed.
 */
void Library_Interface::borrowBook(const std::string& title) {
    std::string lowerTitle = toLowerCase(title); 

    for (auto& book : books) {
        if (toLowerCase(book.getTitle()) == lowerTitle && !book.getBorrowedStatus()) {
            book.borrowBook();
            storage.saveBooks(books);
            std::cout << "Book borrowed: " << title << std::endl;
            return;
        }
    }
    std::cout << "Book not available.\n";
}


/**
 * @brief Returns a borrowed book to the library.
 * 
 * Uses linear search (O(n)) and updates a flag (O(1)).
 * 
 * @param title The title of the book to be returned.
 */
void Library_Interface::returnBook(const std::string& title) {
    std::string lowerTitle = toLowerCase(title); 

    for (auto& book : books) {
        if (toLowerCase(book.getTitle()) == lowerTitle && book.getBorrowedStatus()) {
            book.returnBook();
            storage.saveBooks(books);
            std::cout << "Book returned: " << title << std::endl;
            return;
        }
    }
    std::cout << "Book not found or was not borrowed.\n";
}


/**
 * @brief Lists all books currently in the library.
 * 
 * Uses iteration (O(n)).
 */
void Library_Interface::listBooks() const {
    if (books.empty()) {
        std::cout << "No books in library.\n";
        return;
    }
    std::cout << "Books available in the library:\n";
    for (const auto& book : books) {
        std::cout << "- " << book.getTitle() << " by " << book.getAuthor() << " Published Year " << book.getYear()
                  << (book.getBorrowedStatus() ? " [Unavailable]" : "") << std::endl;
    }
}
