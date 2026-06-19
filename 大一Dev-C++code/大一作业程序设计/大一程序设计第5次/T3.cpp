#include <iostream>
#include <string>
using namespace std;
int main() {
	string n1,n2,n3;
	int n,p1=0,p2=0,p3;
	cin>>n;
	cin>>n3>>p3;
		if(p1<p3) {
			swap(p1,p3);
			swap(n1,n3);}
	for(; n>1;n--) {
		cin>>n3>>p3;
		if(p2<p3) {
			swap(p2,p3);
			swap(n2,n3);
		}
		if(p1<p2) {
			swap(p1,p2);
			swap(n1,n2);
		}
		
			}
cout << "学生" << n1 << "获得最高分" << p1 << endl;
cout << "学生" << n2 << "获得次高分" <<p2 << endl;
	return 0;
}
