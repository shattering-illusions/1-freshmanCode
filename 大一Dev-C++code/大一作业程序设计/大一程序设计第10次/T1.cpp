#include<iostream>
#include<cmath>
using namespace std;
class MyPoint
{
	public:
		MyPoint (double xx=0,double yy=0)
		{
			x=xx;
			y=yy; 
		}
	double distance (MyPoint &other);
	double getX() const { return x;}
	double getY() const { return y;}
	private:
		double x,y;
};
double MyPoint::distance (MyPoint &other)
{
	double xx=x-other.x;
	double yy=y-other.y;
	double d=sqrt(xx*xx+yy*yy);
	return d;
}
int main()
{
	double x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2; 
	MyPoint p1(x1,y1),p2(x2,y2);
	cout<<p1.distance(p2);
	return 0;
}
/*
设计一个名为MyPoint的类，表示直角坐标系中一个点，类包含：

（1）两个表示坐标的数据成员x和y；

（2）一个无参构造函数，创建一个点(0, 0)；

（3）x和y的get函数；

（4）一个名为distance的函数，返回当前点与另一个给定的MyPoint类型点之间距离。

编写测试程序创建两个点，并输出此两点之间的距离。



输入样例（一行为一个点的两坐标）：

0 0

10 30.5

输出样例（使用系统默认精度）：

32.097*/
