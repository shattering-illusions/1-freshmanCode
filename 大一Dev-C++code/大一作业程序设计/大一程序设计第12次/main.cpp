#include"Complex.h"
#include<iostream>
using namespace std; 
int main()
{
	double a, b, c;
	cin >> a >> b >> c;
    Complex c1(a, b);
    Complex c2(c);
    c1.add(c2);
    c1.show();
    return 0;
}
