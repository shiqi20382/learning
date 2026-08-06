#include<iostream>
using namespace std;  
int add(int a , int b )
{
    return a + b;
}

int main()
{
    int a = 10;
    int b = 20;
    cout << "请输入第一个整数: ";
    cin >> a;
    cout << "请输入第二个整数: ";
    cin >> b;
    int sum = add(a, b);
    cout << a << " + " << b << " = " << sum <<endl;
    return 0;
}   