#include "../include/Storage_Interface.hpp"

Storage_Interface::Storage_Interface(const std::string& filename) : storageFile(filename) {}

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
