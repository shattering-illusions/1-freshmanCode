#include<iostream>
using namespace std;
class Base0
{
	public: 
		Base0()
		{
			cout<<"Base0---构造---被调用"<<endl; 
		}
		~Base0()
		{
			cout<<"Base0---析构---被调用"<<endl;
		}
};
class Base1 :virtual public Base0 
{
	public:
		Base1()
		{
			cout<<"Base1---构造---被调用"<<endl; 
		}
		~Base1()
		{
			cout<<"Base1---析构---被调用"<<endl;
		}
};
class Base2:public virtual Base0
{
	public:
		Base2()
		{
			cout<<"Base2---构造---被调用"<<endl; 
		}
		~Base2()
		{
			cout<<"Base2---析构---被调用"<<endl;
		}
};
class Base3:public Base1,public Base2
{
	public:
		Base3()
		{
			cout<<"Base3---构造---被调用"<<endl; 
		}
		~Base3()
		{
			cout<<"Base3---析构---被调用"<<endl;
		}
};
int main()
{
	Base3 a;
	return 0;
}
