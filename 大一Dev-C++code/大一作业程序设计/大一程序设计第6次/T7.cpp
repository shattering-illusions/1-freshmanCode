#include<iostream>
using namespace std;
void sort(double& num1, double& num2, double& num3)
{
	if (num1>num2)
	{
		swap(num1,num2);
	}
	if (num1>num3) 
	{
		swap(num1,num3);
	}
	if (num2>num3) 
	{
		swap(num2,num3);
	}
}

int main()
{ 
	double a,b,c;
	cin>>a>>b>>c;
	sort(a,b,c);
	cout<<a<<" "<<b<<" "<<c<<endl;
	return 0;
}
