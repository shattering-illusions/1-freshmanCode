/*设计一个抽象类Shape：
（1）数据成员：中心坐标（int x, y）;
（2）成员函数：构造函数，计算面积和周长的纯虚函数double getArea()和double getPerimeter();
并由该类派生出
Rectangle类（增加数据成员长和宽int width, length）
Circle类（增加数据成员int radius)，实现各类的getArea()和getPerimeter()函数。
设计全局函数void show(Shape * s)实现各种几何图形面积和周长的输出。实现类并编写主函数测试之。
*/
#include<iostream>
using namespace std;
const double PI=3.14159;
class Shape
{
	private:
		int x,y;
	public:
		Shape(int x =0,int y =0)
		{
			this->x=x;
			this->y=y;
		}
		virtual double getArea() const =0;
		virtual double getPerimeter() const =0;
};
void show(Shape * s)
{
	cout<<"Area     :"<<s->getArea()<<endl;
	cout<<"Perimeter:"<<s->getPerimeter()<<endl; 
}
class Rectangle :public Shape
{
	private:
		double width,length;
	public:
		Rectangle(double length =0,double width=0)
		{
			this->length=length;
			this->width=width;
		}
		virtual double getArea() const
		{
			double area=width*length;
			return area;
		}
		virtual double getPerimeter() const
		{
			double Perim=2*width+2*length;
			return Perim;
		}
};
class Circle :public Shape
{
	private:
		double radius;
	public:
		Circle(double radius = 0)
		{
			this->radius=radius;
		}
		virtual double getArea() const
		{
			double area = PI*radius*radius;
			return area;
		}
		virtual double getPerimeter() const
		{
			double per=PI*radius*2;
			return per;
		}
};
int main()
{
	double width,length,radius;
	cout<<"请输入长方形的长和宽，再输入圆的半径：" ;
	cin>>length>>width>>radius;
	Shape *p;
	Rectangle rect(length,width);
	Circle circle(radius);
	p= &rect;
	cout<<"长方形信息：\n";
	show(p);
	p =&circle;
	cout<<"圆形信息\n";
	show(p);
	return 0;
}
