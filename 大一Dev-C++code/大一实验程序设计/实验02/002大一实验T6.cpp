#include<iostream>
using namespace std;
void f(int x) {
for(int i=2,m=x;i<=m/2;){
if(x%i==0){
	x/=i;
	cout<<i<<" ";}
else
    i++;	
}
}
int main() {
	int x;
	cin>>x;
	f(x);
	return 0;
}
