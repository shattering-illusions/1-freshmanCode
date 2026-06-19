#include<iostream>
using namespace std;
int main() {
	int x,a,b,c,d;
	cin>>x;
	if(x>999&&x<10000) {
		d=x%10;
		c=(x%100-d);
		b=(x%1000-c-d);
		a=x-b-c-d;
		if(a/1000==d&&b/100==c/10)
			cout<<x<<" is huiwen.";
		else
			cout<<x<<" is not huiwen.";
	} else
		cout<<"You are false.";

	return 0;
}
