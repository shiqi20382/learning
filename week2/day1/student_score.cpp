#include <iostream>                              // 引入输入输出库
#include <string>                                // 引入 string 类型

using namespace std;                             // 使用标准命名空间

string getLevel(double score)                    // 在 main 函数外定义等级判断函数
{
    if (score >= 90)                             // 分数大于等于 90
    {
        return "A";                              // 返回 A
    }
    else if (score >= 80)                        // 分数大于等于 80
    {
        return "B";                              // 返回 B
    }
    else if (score >= 70)                        // 分数大于等于 70
    {
        return "C";                              // 返回 C
    }
    else if (score >= 60)                        // 分数大于等于 60
    {
        return "D";                              // 返回 D
    }
    else                                         // 分数小于 60
    {
        return "F";                              // 返回 F
    }
}                                                // 这里结束 getLevel 函数

int main()                                       // 程序从 main 开始执行
{
    string name;                                 // 定义姓名变量
    int age;                                     // 定义年龄变量
    double score;                                // 定义分数变量

    cout << "请输入姓名：" << endl;               // 输出姓名提示
    getline(cin, name);                          // 读取整行姓名

    cout << "请输入年龄：" << endl;               // 输出年龄提示
    cin >> age;                                  // 读取年龄

    cout << "请输入分数：" << endl;               // 输出分数提示
    cin >> score;                                // 读取分数

    if (score < 0 || score > 100)                // 判断分数是否无效
    {
        cout << "分数输入无效" << endl;           // 输出错误提示
        return 1;                                // 以失败状态结束程序
    }

    cout << "\n学生信息：" << endl;               // 输出标题
    cout << "姓名：" << name << endl;             // 输出姓名
    cout << "年龄：" << age << endl;              // 输出年龄
    cout << "分数：" << score << endl;            // 输出分数
    cout << "等级：" << getLevel(score) << endl;  // 调用函数并输出等级

    if (age >= 18)                               // 判断是否成年
    {
        cout << "成年状态：已成年" << endl;       // 输出成年提示
    }
    else                                         // 年龄小于 18
    {
        cout << "成年状态：未成年" << endl;       // 输出未成年提示
    }

    return 0;                                    // 程序正常结束
}                                                // 这里结束 main 函数