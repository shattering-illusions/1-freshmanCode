#include<iostream>
using namespace std;
int main() {
	double x,zheng=0,fu=0,sum=0,n=0;
	do {
		cin>>x;
		if(x>0)
			zheng++;
		else if(x<0)
			fu++;
		n++;
		sum+=x; 
	} while(x!=0);
		if(zheng==0&&fu==0)
			cout<<"未输入任何有效数";
		else 
			cout<<"正数个数"<<zheng<<endl;
			cout<<"负数个数"<<fu<<endl; 
			cout<<"总和"<<sum<<endl<<"平均值"<<sum*1.0/(n-1); 
		
	return 0;
}
