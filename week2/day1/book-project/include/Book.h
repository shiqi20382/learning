#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
public:
    Book(const std::string& title, int id, double price);
    void printInfo() const;
    std::string getTitle() const;
    int getId() const;
    double getPrice() const;
private:
    std::string title_;
    int id_;
    double price_;
};  
#endif // BOOK_H