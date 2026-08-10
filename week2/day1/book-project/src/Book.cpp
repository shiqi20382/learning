#include "Book.h"                                     // 引入 Book 类声明
#include <iostream>                                   // 引入 cout 和 endl

Book::Book(const std::string& title, int id, double price) // 实现图书构造函数
    : title_(title), id_(id), price_(price)           // 使用初始化列表初始化成员变量
{
}

void Book::printInfo() const                          // 实现输出图书信息函数
{
    std::cout << "书名：" << title_                   // 输出书名
              << "，编号：" << id_                   // 输出编号
              << "，价格：" << price_                // 输出价格
              << std::endl;                          // 换行
}

int Book::getId() const                               // 实现获取图书编号函数
{
    return id_;                                       // 返回图书编号
}

std::string Book::getTitle() const                    // 实现获取图书书名函数
{
    return title_;                                    // 返回图书书名
}

double Book::getPrice() const                         // 实现获取图书价格函数
{
    return price_;                                    // 返回图书价格
}