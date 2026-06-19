#include <iostream>
using namespace std;
void f() {
	int n,m1,cs;
	do {
		cin>>n;
		if(n==0)
			break;
		if(n==m1)
			cs++;
		if(n>m1) {
			swap(n,m1);
			cs=1;
		}
	} while(true);
	cout<<"最大数"<<m1<<endl;
	cout<<"次数"<<cs;
}
int main() {
	f();
	return 0;
}
