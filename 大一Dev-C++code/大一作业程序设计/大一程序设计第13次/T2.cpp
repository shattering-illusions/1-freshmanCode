#include <iostream>
#include<cmath>
using namespace std;

class Complex
{
	private:
		double real,image;
	public:
		Complex(double _real = 0,double _image = 0)
		{
			real = _real;
			image = _image;
		}
		void print() const ;
		Complex operator + (const Complex& other);
		Complex operator - (const Complex& other);
		Complex operator * (const Complex& other);
		Complex operator / (const Complex& other);
		Complex& operator ++ ();
		Complex operator ++ (int);
		
};
Complex  Complex::operator + (const Complex& other)
{
	double r =real+other.real,i = image + other.image;
	Complex c(r,i);
	return c;
}
Complex  Complex::operator - (const Complex& other)
{
	double r =real-other.real,i = image - other.image;
	Complex c(r,i);
	return c;	
}
Complex  Complex::operator * (const Complex& other)
{
	double r =real*other.real-image*other.image,i =real*other.image+other.real*image;
	Complex c(r,i);
	return c;
}
Complex  Complex::operator / (const Complex& other)
{
	double r =(real*other.real+image*other.image)/(pow(other.image,2)+pow(other.real,2)) ,i = (image*other.real-real*other.image)/(pow(other.image,2)+pow(other.real,2));
	Complex c(r,i);
	return c;
}
Complex&  Complex::operator ++ ()
{
	real+=1;
	image+=1;
	return *this;
}
Complex  Complex::operator ++ (int)
{
	Complex mode = *this;
	++ *this ;
	return mode;
}
void Complex::print() const
{
	int pd1=0,pd2=0;
	if(real !=0)
		pd1=1;
	if(image<0)
		pd2=-1;
	else if(image>0)
		pd2=1;
	if(pd1==0&&pd2==0)
	{
		cout<<"0"<<endl;
	}
	else if(pd1==0&&pd2==-1)
	{
		cout<<"- "<<abs(image)<<"i"<<endl;
	}
	else if(pd1==0&&pd2==1)
	{
		cout<<"+ "<<image<<"i"<<endl;
	}
	else if(pd1==1&&pd2==0)
	{
		cout<<real<<"\n";
	}
	else if(pd1==1&&pd2==-1)
	{
		cout<<real<<" - "<<abs(image)<<"i"<<endl;
	}
	else if(pd1==1&&pd2==1)
	{
		cout<<real<<" + "<<image<<"i"<<endl;
	}
}
int main() {
	double real1, imag1, real2, imag2;
	cin >> real1 >> imag1 >> real2 >> imag2;

    Complex c1(real1, imag1);
    Complex c2(real2, imag2);

    Complex c3 = c1 + c2;
    cout << "c1 + c2 = ";
	c3.print();

    c3 = c1 - c2;
    cout << "c1 - c2 = ";
	c3.print();

    c3 = c1 * c2;
    cout << "c1 * c2 = ";
	c3.print();

    c3 = c1 / c2;
    cout << "c1 / c2 = ";
	c3.print();

    c3 = ++c1;
    cout << "++c1 = ";
	c3.print();

    c3 = c1++;
    cout << "c1++ = ";
	c3.print();
    return 0;
}
