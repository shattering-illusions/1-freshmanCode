#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main() {
	cout<<left<<setw(12)<<"Degree"<<setw(12)<<"Sin"<<"Cos"<<endl;
	double n=0,PI=3.14159,du,s,c;
	for(; n<81; n+=10) {
		du=PI*n/180.0;
		cout<<fixed<<setprecision(0)<<left<<setw(12)<<n<<fixed<<setprecision(4)<<setw(12)<<sin(du)<<cos(du)<<endl;
	}return 0;
}
