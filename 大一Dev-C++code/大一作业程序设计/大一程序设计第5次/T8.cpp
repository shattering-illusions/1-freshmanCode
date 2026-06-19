#include<iostream>

using namespace std;
void wqs() {

	for(int i=1; i<=10000; i++) {
		int sum=0;
		for(int n=1,z=i; n<=(i/2); n++ ) {
			if(i%n==0)
				sum+=n;
		}
		if(sum==i)
			cout<<i<<endl;

	}
}
int main() {
	wqs();
	return 0;
}
