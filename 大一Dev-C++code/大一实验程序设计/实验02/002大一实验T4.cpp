#include<iostream>
using namespace std;
void f() {
for(int i=1;i<1000;i++){
	int sum=0;
	for(int z=1;z<=i/2;z++){
	if(i%z==0){
		sum+=z;
	}	
	}
	if(sum==i)
	cout<<i<<endl;	
}
}
int main() {
	f();
	return 0;
}
