#include<iostream>
#include<cmath>
using namespace std;
class Point {
	private:
		int x, y;
	public:
		Point(int x=0, int y=0) {
			this->x=x;
			this->y=y;
		}
		int getX() const {
			return x;
		}
		int getY() const {
			return y;
		}
		void show() { // 输出点坐标
			cout<<"( "<<x<<" , "<<y<<" )"<<endl;
		}
};

class Line {
	private:
		Point p1, p2;
	public:
		Line(int x1, int y1, int x2, int y2) {
			p1 = Point(x1,y1);
			p2 = Point(x2,y2);
		}
		Line(Point p1, Point p2) {
			this->p1=p1;
			this->p2=p2;
		}
		Line() {
			p1 = Point (0,0);
			p2 = Point (0,0);
		}
		double length() {
			double length = sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX())+(p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
			return length;
		}
		Point getP1() const {
			return p1;
		}
		Point getP2() const {
			return p2;
		}
		void show() { // 输出直线两个端点坐标
			cout<<"端点1坐标:";
			p1.show();
			cout<<"端点2坐标:";
			p2.show();
		}
};

class Polygon {
	private:
		Line *p;
		int edges;
	public:
		Polygon(Line *p_, int edge_num) {
			edges = edge_num;
			p = new Line[edge_num];
			for(int i = 0; i<edge_num; i++)
				p[i]=p_[i];
		}
		Polygon(Point *p_, int point_num) { // 由一组顶点来构造多边形，组边来构造多边形，一组顶点有Point对象数组给出
			edges = point_num;
			p = new Line[point_num];
			for(int i=0; i<point_num-1; i++)
				p[i]=Line(p_[i],p_[i+1]);
			p[point_num-1]=Line(p_[point_num-1],p_[0]);
		}
		Polygon(const Polygon &other) { // 拷贝构造函数
			edges=other.edges;
			p = new Line[other.edges];
			for(int i = 0 ; i,other.edges; i++)
				p[i]=other.p[i];
		}
		double getArea() { // 计算多边形面积
			double Area=0;
			int x1 = p[0].getP1().getX();
			int y1 = p[0].getP1().getY();
			for(int i = 0; i< edges-2; i++) {
				int x2=p[i].getP2().getX();
				int y2=p[i].getP2().getY();
				int x3=p[i+1].getP2().getX();
				int y3=p[i+1].getP2().getY();
				double S=0.5* (x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1);
				Area+=abs(S);
			}
			return Area;
		}
		double getPerimeter() { //计算多边形周长
			double per = 0;
			for(int i = 0; i<edges; i++)
				per+=p[i].length();
			return per;
		}
		void show() { // 输出多边形顶点序列、一组边有Line对象数组给出周长及面积
			cout<<"周长为:"<<this->getPerimeter()<<endl;
			cout<<"面积为:"<<this->getArea()<<endl;
		}
		~Polygon() { // 析构函数
			delete [] p;
		}
};
int main() {
	Point *p = new Point[4];
	cout<<"注：所有测试数据在main函数中设置."<<endl;
	cout<<"---开始测试点----------"<<endl;
	p[0]=Point(1,2);
	p[0].show();
	cout<<"---开始测试线----------"<<endl;
	p[1]=Point(5,2);
	Line l1(p[0],p[1]);
	l1.show();
	cout<<"线长为:"<<l1.length()<<endl;
	cout<<"---开始测试多边形------"<<endl;
	p[2]=Point(1,6);
	p[3]=Point(5,6);
	Polygon zfx(p,4);
	zfx.show();
	return 0;
}
/*提示：
（1）对于逆时针排列的三个顶点A(x1, y1)、B(x2, y2)、C(x3, y3)，三角形面积为：
S=0.5 * (x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1)，多边形面积由多个三角形求和而成。
（2）Polygon类多边形的边数在设计时是无法确定的，只有在运行时才能确定，
因此多边形边的数据用动态数组（new）来存储。Polygon类里只存放多边形边数据数组的首地址。
因为用了new创建的动态数组，所以拷贝构造函数、析构函数需用户定义*/

