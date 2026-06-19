#include<iostream>
using namespace std;
void f(int a,int n){
int sum1=0,sum2=0;
for(int i=n;i!=0;i--){
sum2=sum2*10+1;
sum1+=a*sum2;
}
cout<<sum1;
}
int main() {
	int a,n;
	cin>>a>>n;
	f(a,n);
	return 0;
}
