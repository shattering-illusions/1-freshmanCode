#include <iostream>
using namespace std;
#define PI 3.14159

class Shape
{
	public:
	virtual double getArea() const =0;
	virtual double getPerim() const =0; 
};

class Rectangle : public Shape
{
	private:
		double width,height;
	public:
		Rectangle(double width_=0,double height_=0)
		{
			width=width_;
			height=height_;
		}
		double getArea() const
		{
			double area=width*height;
			return area;
		}
		double getPerim() const
		{
			double perim = 2*width+2*height;
			return perim;
		}
};

class Circle : public Shape
{
	private:
		double radius;
	public:
		Circle(double radius=0)
		{
			this->radius=radius;
		}
		double getArea() const
		{
			double area=PI*radius*radius;
			return area;
		}
		double getPerim() const
		{
			double perim = 2*PI*radius;
			return perim;
		}
};

class Square : public Rectangle
{
	private:
		double side;
	public:
		Square(double side_=0)
		{
			side=side_;
		}
		double getPerim() const
		{
			double perim=4*side;
			return perim;
		}
		double getArea() const
		{
			double area=side*side;
			return area;
		}
};

int main() {
	double width, height, radius, side;
	cin >> width >> height >> radius >> side;

    Rectangle rect(width, height);
    Circle cir(radius);
    Square sq(side);

    cout << "矩形的面积：" << rect.getArea() << endl;
    cout << "矩形的周长：" << rect.getPerim() << endl;

    cout << "圆的面积：" << cir.getArea() << endl;
    cout << "圆的周长：" << cir.getPerim() << endl;

    cout << "正方形的面积：" << sq.getArea() << endl;
    cout << "正方形的周长：" << sq.getPerim() << endl;

    return 0;
}
/*编写一个抽象类Shape，包含两个纯虚函数getArea( )计算面积，getPerim( )计算周长，
在此基础上派生Rectangle类和Circle类，给出纯虚函数的具体实现。
通过继承Rectangle类，创建一个派生类Square。
在主函数里创建类对象进行测试。
输入样例（分别对应矩形宽、高，圆半径，正方形边长）：

4.4 5.5 3.3 2.2
输出样例：

矩形的面积：24.2
矩形的周长：19.8
圆的面积：34.2119
圆的周长：20.7345
正方形的面积：4.84
正方形的周长：8.8
*/
