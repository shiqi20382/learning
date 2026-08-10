#include "BookManager.h"                              // 引入图书管理类
#include <iostream>                                   // 引入 cout 和 endl

int main()                                            // 程序入口函数
{
    BookManager manager;                              // 创建图书管理器对象

    manager.addBook(Book("C++ Primer", 1001, 99.50)); // 添加第 1 本图书
    manager.addBook(Book("Linux Basics", 1002, 68.00)); // 添加第 2 本图书
    manager.addBook(Book("Git Guide", 1003, 45.50)); // 添加第 3 本图书

    std::cout << "全部图书信息：" << std::endl;        // 输出标题
    manager.printAllBooks();                          // 输出所有图书信息

    Book* book = manager.findBookById(1002);          // 查找编号为 1002 的图书

    if (book != nullptr)                              // 如果找到了图书
    {
        std::cout << "找到图书："                     // 输出找到提示
                  << book->getTitle()                 // 通过指针获取图书书名
                  << std::endl;                       // 换行
    }
    else                                              // 如果没有找到图书
    {
        std::cout << "没有找到图书" << std::endl;      // 输出未找到提示
    }

    book = manager.findBookById(9999);                // 查找一个不存在的编号

    if (book != nullptr)                              // 如果意外找到了图书
    {
        std::cout << "找到图书："                     // 输出找到提示
                  << book->getTitle()                 // 输出图书书名
                  << std::endl;                       // 换行
    }
    else                                              // 如果没有找到图书
    {
        std::cout << "没有找到编号为 9999 的图书"      // 输出未找到提示
                  << std::endl;                       // 换行
    }

    std::cout << "全部图书价格总和："                  // 输出总价提示
              << manager.getTotalPrice()              // 调用函数计算并输出总价格
              << std::endl;                           // 换行

    return 0;                                         // 返回 0，表示程序正常结束
}