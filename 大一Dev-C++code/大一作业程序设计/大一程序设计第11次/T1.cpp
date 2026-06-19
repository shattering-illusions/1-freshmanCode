#include <iostream>
using namespace std;
class MyInt {
private:
    int value;
public:
    // 无参构造函数
    MyInt()
	{
		value=0;
		cout<<"无参构造函数被调用" <<endl;
    }
    // 有参构造函数
    MyInt(int val)
	{
		value=val;
		cout<<"有参构造函数被调用"<<endl;
    }
    // 拷贝构造函数
    MyInt(const MyInt& other)
	{
		value=other.value;
		cout<<"拷贝构造函数被调用"<<endl;
    }
    // 析构函数
    ~MyInt()
	{
		cout<<"析构函数被调用"<<endl;
    }

    // 给整型数赋值
    void setValue(int val)
	{
		value=val;
    }
    // 读取整型数
    int getValue()
	{
		return value;
    }
    // 质数判断
    bool isPrime()
	{
		int pd=1;
		for(int i=2;i<(value+1)/2;i++)
			if(value%i==0)
				pd++;
		return pd==1;
    }
    // 回文数判断
    bool isPalindrome()
	{
		int back_value=0;
		for(int i=value;i>=1;i/=10)
			back_value=back_value*10+i%10;
		return value==back_value;
	}
    // 计算位数
    int countDigits()
	{
		int countDights=0;
		for(int i=value;i>=1;i/=10)
			countDights++;
		return countDights;
    }
};
int main() {
    int n;
	cin >> n;
	MyInt a;
    a.setValue(n);
    MyInt b(a);
    cout << "值：" << b.getValue() << endl;
    cout << "是否质数：" << (b.isPrime() ? "是" : "否") << endl;
    cout << "是否回文数：" << (b.isPalindrome() ? "是" : "否") << endl;
    cout << "位数：" << b.countDigits() << endl;
    return 0;
}
/*定义一个整数类MyInt，其功能包括：
（1）无参构造函数，可以不赋值，或者赋固定值，并输出“无参构造函数被调用”；
（2）有参构造函数，实现对整数的初始化，并输出“有参构造函数被调用”；
（3）拷贝构造函数，实现用整数类类对象为其初始化，并输出“拷贝构造函数被调用”；
（4）析构函数，在析构函数中输出“析构函数被调用”；
（5）分别定义成员函数，分别实现如下功能：给整型数赋值，读取整型数，质数判断、回文数判断、计算位数。
编写主函数测试定义的类（基于答题模板答题，勿修改main函数*/
