#include <iostream>                              // 引入输入输出库
#include <string>                                // 引入 string 类型所在的库

using namespace std;                             // 使用标准命名空间

int main()                                       // 程序入口函数
{
    string name;                                 // 定义字符串变量，用来保存姓名
    int age;                                     // 定义整数变量，用来保存年龄

    cout << "请输入你的姓名：";                   // 输出姓名输入提示
    getline(cin, name);                          // 读取一整行文字，支持输入含空格的姓名

    cout << "请输入你的年龄：";                   // 输出年龄输入提示
    cin >> age;                                  // 读取用户输入的整数年龄

    cout << "你好，" << name                     // 输出问候语和姓名
         << "，你今年 " << age                   // 输出年龄
         << " 岁。" << endl;                     // 输出句尾并换行

    return 0;                                    // 返回 0，表示程序正常结束
}