#include<iostream>
#include<string>
using namespace std;
void zss() {
	for(int i=1,m=0; i<1000; i++) {
		if(i<=9) {
			m=(i*i)%10;
			if(m==i)
				cout<<i<<endl;
		} else if(i<=99&&i>=10) {
			m=(i*i/10)%10*10+(i*i)%10;
			if(m==i)
				cout<<i<<endl;
		} else if(i<=999&&i>=100) {
			m=(i*i/100)%100*100+(i*i/10)%10*10+(i*i)%10;
			if(m==i)
				cout<<i<<endl;
		}
	}
}
int main() {
	zss();
	return 0;
}
