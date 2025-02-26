#ifndef STORAGE_INTERFACE_H
#define STORAGE_INTERFACE_H

#include "Constant_Headers.hpp"
#include "Book_Interface.hpp"

class Storage_Interface {
    private:
        std::string storageFile;
    
    public:

        Storage_Interface(const std::string& filename);

        std::vector<Book_Interface> loadBooks();

        void saveBooks(const std::vector<Book_Interface>& books);
    };

#endif