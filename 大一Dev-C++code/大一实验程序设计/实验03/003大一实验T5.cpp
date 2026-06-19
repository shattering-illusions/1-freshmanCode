#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
long long jc(int i)
{
	int n=i; 
	while(n>1)
	{
		i*=(n-1); 
		n--;
	}
	return i;
}
double myCos(double jd)
{
	const double pi=3.14159;
	double hd=pi*jd/180.0;
	for(;hd>=2*pi||hd<=-2*pi;)
	{
		if(hd>=2*pi)
		hd-=2*pi;
		else if(hd<=-2*pi)
		hd+=2*pi;
	}
	double sum=1.0,e=1.0;
	int n=1;
	do
	{
		e=-1*e*hd*hd/((2*n-1)*2*n);
		sum+=e;
		n++;
	}while(fabs(e)>=0.00000001);
	return sum;
}
int main()
{
	double jiaodu;
	cout<<"请输入角度x（以度为单位）:" <<endl;
	cin>>jiaodu;
	cout<<"cos(x)的值为："<<fixed<<setprecision(4)<<myCos(jiaodu);
	return 0;
}
