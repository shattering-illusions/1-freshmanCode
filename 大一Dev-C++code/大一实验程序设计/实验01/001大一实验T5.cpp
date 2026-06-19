#include<iostream>
using namespace std;
int main() {
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b<=c||a+c<=b||b+c<=a)
		cout<<"They cannot form a triangle";//bushi sanjiaoxing
	else {
		if(a==b&&b==c)
			cout<<"Equilateral triangle";//dengbian
		else if(a*a+b*b==c*c||a*a+c*c==b*b||c*c+b*b==a*a)
			cout<<"right triangle";//zhijiao
		else
			cout<<"scalene triangle";//putong
	}
	return 0;
}

