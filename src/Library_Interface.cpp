#include "../include/Library_Interface.hpp"

Library_Interface::Library_Interface(Storage_Interface& storage) : storage(storage) {
    books = storage.loadBooks();
}

// Function to convert a string to lowercase
std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) {
        return std::tolower(c); 
    }
    );
    return lowerStr;
}

void Library_Interface::addBook(const Book_Interface& book) {
    books.push_back(book);
    storage.saveBooks(books);
    std::cout << "Book added: " << book.getTitle() << std::endl;
}


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

void Library_Interface::removeAllBooks() {
    books.clear();
    storage.saveBooks(books);
    std::cout << "All books have been removed from the library.\n";
}


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
