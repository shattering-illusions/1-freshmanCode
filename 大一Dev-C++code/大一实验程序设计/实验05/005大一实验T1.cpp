#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Point
{
	public:
		Point(double xx=0, double yy=0)
		{
			x=xx;
			y=yy;
		};
		Point(Point& p):
		x(p.x),y(p.y)
		{
		};
		void pan(double delta_x, double delta_y);
		double dist();
		void rotate(double alpha);
		double getX()
		{
			return x;
		};
		double getY()
		{
			return y;
		};
		void display()
		{ 
			cout<<fixed<<setprecision(4)<<"点为("<<x<<","<<y<<")";
		};
	private:
		double x,y;
};
double Point::dist()
{
	double n=sqrt(x*x+y*y);
	return n;
}
void Point::pan(double delta_x,double delta_y)
{
	x+=delta_x;
	y+=delta_y;
}
void Point::rotate(double alpha)
{
	const double PI=3.14159;
	double hud1=alpha*PI/180.0,hud2=atan(y/x);
	cout<<hud2<<endl;
	x=sqrt(x*x+y*y)*cos(hud1-hud2);
	y=sqrt(x*x+y*y)*sin(hud1-hud2);
}
int main()
{
	double x,y,x_,y_,a;
	cout<<"输入点p的x坐标和y坐标。"<<endl; 
	cin>>x>>y;
	Point p1(x,y);
	cout<<"点到原点的距离为"<<p1.dist()<<endl;
	cout<<"请输入将点向右平移的数，向上平移的数.\n";
	cin>>x_>>y_;
	p1.pan(x_,y_);
	cout<<"点的横坐标为:"<<p1.getX()<<endl;
	cout<<"点的纵坐标为:"<<p1.getY()<<endl;
	cout<<"请输入将点顺时针旋转的度数."<<endl;
	cin>>a;
	p1.rotate(a);
	p1.display();
	return 0;
}
/*
设计一个点类Point，并编写主函数测试之。
数据成员有：
横坐标(double x)，纵坐标(double y)；
成员函数有：
①构造函数Point(double xx = 0,  double yy = 0)，
②点到原点距离函数double dist()，
③点的平移函数void pan(double delta_x, double delta_y)，
④点绕原点旋转函数void rotate(double alpha)，
⑤点坐标获取函数double getX()，double getY()，
⑥点坐标输出函数void display()。
*/
