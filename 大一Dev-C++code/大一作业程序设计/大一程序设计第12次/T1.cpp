/*
定义一个基类Base类，有成员函数fn1( )和fn2( )，从它派生出Derived类，重新定义了成员函数fn1( )和fn2( )；
在主函数中声明Derived类对象，分别用Derived的类对象、Base类指针和Derived类指针调用fn1( )和fn2( ) ，
显示运行结果如下：
使用Derived对象调用:
Derived::fn1()
Derived::fn2()
使用Base指针调用:
Base::fn1()
Base::fn2()
使用Derived指针调用:
Derived::fn1()
Derived::fn2()
*/
#include <iostream>
using namespace std;
class Base
{
	public:
		void fn1()
		{
			cout<<"Base::fn1()"<<endl;
		}
		void fn2()
		{
			cout<<"Base::fn2()\n";
		}
};
class Derived : public Base
{
	public:
		void fn1()
		{
			cout<<"Derived::fn1()\n";
		}
		void fn2()
		{
			cout<<"Derived::fn2()\n";
		}
};
int main() {
    Derived d;
    Base* bp = &d;
    Derived* dp = &d;

    cout << "使用Derived对象调用:" << endl;
    d.fn1();
    d.fn2();

    cout << "使用Base指针调用:" << endl;
    bp->fn1();
    bp->fn2();

    cout << "使用Derived指针调用:" << endl;
    dp->fn1();
    dp->fn2();

    return 0;
}

