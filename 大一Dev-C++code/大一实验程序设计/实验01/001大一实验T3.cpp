#include<iostream>
using namespace std;
int main() {
	double m,r,q;
//cout<<"Please enter the mouth and number of people:";
	cin>>m>>r;
	if(m>=7&&m<=9&&r>=20) {
		q=398*r*0.7;
		cout<<q;
	} else if(m>=7&&m<=9&&r<20) {
		q=398*r*0.85;
		cout<<q;
	} else if((m<7||m>9)&&r>=20) {
		q=398*r*0.5;
		cout<<q;
	} else if((m<7||m>9)&&r<20) {
		q=398*r*0.7;
		cout<<q;
	}
	return 0;
}
