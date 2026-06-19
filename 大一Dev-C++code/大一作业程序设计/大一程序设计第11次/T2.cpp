/*定义复数类Complex，使得下面代码能够工作

Complex c1(3, 5);        //用复数3+5i初始化c1

Complex c2(4.5);       //用实数4.5初始化

c1.add(c2);                   //将c1和c2相加保存在c1

c1.show();                    //将c1输出

基于答题模板答题，勿修改其中的main函数。



输入样例：

3 5

4.5

输出样例：

7.5 + 5i*/
#include <iostream>
using namespace std;

class Complex
{
	private:
		double realPart,imaginaryPart;
	public:
		Complex(double real=0,double imaginary=0)
		{
			realPart=real;
			imaginaryPart=imaginary;
		}
		void add(Complex &c)
		{
			realPart+=c.realPart;
			imaginaryPart+=c.imaginaryPart;
		}
		void show() const
		{
			if(realPart!=0)
				cout<<realPart<<" + ";
			if(imaginaryPart!=0)
				cout<<imaginaryPart<<"i"<<endl;
			if(realPart==0&&imaginaryPart==0)
				cout<<"0"<<endl;
		}
};

int main()
{
	double a, b, c;
	cin >> a >> b >> c;
    Complex c1(a, b);
    Complex c2(c);
    c1.add(c2);
    c1.show();
    return 0;
}

