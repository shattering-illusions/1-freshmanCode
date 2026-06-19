#include <iostream>
using namespace std;
#define PI 3.14159
class Point
{
	private:
		int x,y;
	public:
		Point(int x=0,int y=0)
		{
			this->x=x;
			this->y=y;
		}
		void setPosition(int x,int y)
		{
			this->x=x;
			this->y=y;
		}
		void display() const
		{
			cout<<"("<<x<<", "<<y<<")";
		}
};
class Circle
{
	private:
		double radius;
		Point position;
	public:
		Circle(double r=0,Point p=Point())
		{
			radius=r;
			position=p;
			count++;
		}
		void displayRadiusAndPosition() const
		{
			cout<<"Radius: "<<radius<<", "<<"Position: ";
			position.display();
			cout<<endl;
		}
		double calculateArea() const
		{
			double area = radius*radius*PI;
			return area;
		}
		static int count; 
		static void displayCount()
		{
			cout<<"Circle count: "<< count<<endl;
		}
};
int Circle::count=0; 
int main() {
	int x, y;
	double r;
	cin >> x >> y >> r;
    Point p1;
    p1.setPosition(x, y);
    Circle c1(r, p1);
    c1.displayRadiusAndPosition();
    cout << "Area: " << c1.calculateArea() << endl;
    Circle a[3];
    Circle::displayCount();
    return 0;
}
/*声明一个Point类：有参构造函数，设置位置函数，显示位置函数；

声明一个Circle类：

（1）数据成员：半径radius，圆心位置position（position是Point类的类对象），静态变量记录圆的个数；

（2）函数成员：有参构造函数，实现对Point有参构造函数传递参数；计算面积函数；设置半径和位置函数；显示半径和位置函数；静态函数显示圆的个数。

注意：为了安全，哪些函数可以设置为常函数。

编写程序测试声明的类（基于答题模板答题，勿修改其中的main函数）。



输入样例：

1 2 2.5

输出样例：

Radius: 2.5, Position: (1, 2)

Area: 19.6349

Circle count: 4*/ 

