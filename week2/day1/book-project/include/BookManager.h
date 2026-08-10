#ifndef BOOK_MANAGER_H                                // 防止 BookManager.h 被重复包含
#define BOOK_MANAGER_H                                // 定义头文件保护标记

#include "Book.h"                                     // 引入 Book 类
#include <vector>                                     // 引入 vector 容器

class BookManager                                      // 定义图书管理类
{
public:                                               // 公共成员区域
    void addBook(const Book& book);                   // 添加图书对象
    Book* findBookById(int id);                       // 根据编号查找图书，找不到时返回 nullptr
    void printAllBooks() const;                       // 输出所有图书信息
    double getTotalPrice() const;                     // 计算所有图书价格总和

private:                                              // 私有成员区域
    std::vector<Book> books_;                         // 使用 vector 保存多个图书对象
};

#endif                                                // 结束头文件保护