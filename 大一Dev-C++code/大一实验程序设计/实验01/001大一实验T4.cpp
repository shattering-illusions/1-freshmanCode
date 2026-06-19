#include<iostream>
using namespace std;
int main() {
	double g,w,sum;
	//cout<<"Please enter the grade and awrd:";
	cin>>g>>w;
	if(w==1)
		sum=g+10;
	else if(w==2)
		sum=g+8;
	else if(w==3)
		sum=g+5;
	else if(w==4)
		sum=g+2;
	if(sum>=100)
		cout<<"100";
	else
		cout<<sum;
	return 0;
}
