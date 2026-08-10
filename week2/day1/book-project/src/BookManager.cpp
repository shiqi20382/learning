#include "BookManager.h"                              // 引入 BookManager 类声明

void BookManager::addBook(const Book& book)           // 实现添加图书函数
{
    books_.push_back(book);                           // 将图书对象添加到 vector 尾部
}

Book* BookManager::findBookById(int id)               // 实现按编号查找图书函数
{
    for (Book& book : books_)                         // 遍历所有图书；使用引用以便返回对象地址
    {
        if (book.getId() == id)                       // 判断当前图书编号是否匹配
        {
            return &book;                             // 找到后返回当前图书对象的地址
        }
    }

    return nullptr;                                   // 所有图书都不匹配时返回空指针
}

void BookManager::printAllBooks() const               // 实现输出全部图书信息函数
{
    for (const Book& book : books_)                   // 遍历所有图书；const 表示只读取
    {
        book.printInfo();                             // 调用每本图书的输出函数
    }
}

double BookManager::getTotalPrice() const             // 实现计算价格总和函数
{
    double total_price = 0;                           // 定义总价格变量，初始值为 0

    for (const Book& book : books_)                   // 遍历所有图书
    {
        total_price += book.getPrice();               // 将当前图书价格累加到总价格
    }

    return total_price;                               // 返回价格总和
}