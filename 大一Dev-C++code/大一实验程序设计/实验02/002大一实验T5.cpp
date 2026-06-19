#include<iostream>
using namespace std;
int f(int x) {
	int bn=0;
	for(int m=x;m>=1;m/=10){
	bn=m%10+bn*10;
	}
	return bn;
}
int main() {
	int x;
	cin>>x; 
	cout<<f(x);
	return 0;
}
