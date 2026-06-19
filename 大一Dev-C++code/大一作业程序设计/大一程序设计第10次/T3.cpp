#include<iostream>

using namespace std;
class EvenNumber
{
	public:
		EvenNumber() { value=0;}
		EvenNumber(int value)
		{
			this->value=value;
		}
		int getValue() const;
		EvenNumber getNext()const;
		EvenNumber getPrevious()const;
	private:
		int value;
};
inline int EvenNumber::getValue() const
{
	return value;
}
EvenNumber EvenNumber::getNext()const
{
	int n=value;
	if(n%2==0)
		n+=2;
	else
		n+=1;
	return EvenNumber(n); 
}
EvenNumber EvenNumber::getPrevious()const
{
	int n=value;
	if(n%2==0)
		n-=2;
	else
		n-=1;
	return EvenNumber(n);
}
int main()
{
	int n;
	cin>>n;
	EvenNumber a(n);
	cout<<a.getNext().getValue()<<endl;
	cout<<a.getPrevious().getValue()<<endl;
	return 0;
}
/*
定义表示偶数的类EvenNumber，类包含：
（1）int型数据成员value，表示对象存储的整型数；
（2）一个无参构造函数，为数值0创建EvenNumber对象；
（3）一个构造函数，为特定数值创建EvenNumber对象；
（4）成员函数getValue( )返回对象存储的int型值；
（5）成员函数getNext( )返回本对象表示的数值的下一个偶数所对应的EvenNumber对象；
（6）成员函数getPrevious()返回本对象表示的数值的前一个偶数所对应的EvenNumber对象。
编写测试程序为键盘输入数值创建EvenNumber对象，调用getNext()和getPrevious( )获取并输出相应偶数值。
输入样例：
16
输出样例：
18
14*/
