#include <iostream>
using namespace std;

#define PI 3.14159 

class Shape
{
	protected:
		double height;
	public:
		virtual void dispInfo() const = 0;
		virtual double compVol() const = 0;
};

class Cuboid : public Shape //长方体 
{
	private:
		double length,width;
	public:
		Cuboid(double length_ = 0,double width_ = 0,double height_ = 0)
		{
			length = length_;
			width = width_;
			height = height_;
		}
		virtual void dispInfo() const;
		virtual double compVol() const
		{
			double V=length*width*height;
			return V;
		}
};
void Cuboid::dispInfo() const
{
	cout<<"长方体长="<<length<<"，宽="<<width<<"，高="<<height<<endl;
}

class Cylinder : public Shape //圆柱体 
{
	private:
		double radius;
	public:
		Cylinder(double radius = 0,double height = 0)
		{
			this->radius = radius;
			this->height = height;
		}
		virtual void dispInfo() const; 
		virtual double compVol()  const
		{
			double V = height* PI*radius * radius;
			return V;
		}
};
void Cylinder::dispInfo() const
{
	cout<<"圆柱体半径="<<radius<<"，高="<<height<<endl;
}

int main() {
	double length, width, height, radius;
	
	cin >> length >> width >> height; 
    Shape* shape1 = new Cuboid(length, width, height);
    
    cin >> radius >> height;
    Shape* shape2 = new Cylinder(radius, height);

    shape1->dispInfo();
    cout << "体积：" << shape1->compVol() << endl;

    shape2->dispInfo();
    cout << "体积：" << shape2->compVol() << endl;

    delete shape1;
    delete shape2;

    return 0;
}
/*如图所示类结构，在充分体现多态特性的前提下，设计长方体类Cuboid与圆柱体类Cylinder，实现如下两个功能：
（1）输出信息：在Cuboid类中实现对立方体信息（长、宽、高）的输出；
在Cylinder类中实现对圆柱体信息（半径、高）的输出；
（2）计算体积：分别在两个类中实现对长方体和圆柱体体积的计算。
要求：
①对长方体类Cuboid和圆柱体类Cylinder共性进行抽象，构成它们共同的基类Shape，
即把长方体类Cuboid与圆柱体类Cylinder共性的数据（高）定义为Shape类的数据成员；
共性的功能函数（输出信息、计算体积）在Shape类里统一接口，构成Shape类的成员函数；
②在两个派生类中分别给出功能函数（输出信息、计算体积）的具体实现；
③在主函数中通过动态绑定的方式，利用基类指针实现对派生类中成员函数（输出信息、计算体积）的调用；
④对部分命名进行如下规定：输出信息函数名为dispInfo，计算体积函数名为compVol；
长、宽、高、半径分别命名为length、width、height、radius；
⑤为了配合功能实现，自行增加其他类成员，如构造函数、对数据成员进行赋值的函数等。
输入样例（分别对应长方体的长宽高和圆柱体的半径、高）：
1 2 3
4 5
输出样例（其中逗号、冒号为中文标点符号，无空格）：

长方体长=1，宽=2，高=3
体积：6
圆柱体半径=4，高=5
体积：251.32
*/
