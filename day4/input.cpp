#include<iostream>
using namespace std;
int main()
{
    int age;
    cout << "请输入年龄: ";
    cin >> age;
    if (age < 18) 
    {
        cout << "未成年" << endl;
    } 
    else 
    {
        cout << "成年人" << endl;
    }
    return 0;
}