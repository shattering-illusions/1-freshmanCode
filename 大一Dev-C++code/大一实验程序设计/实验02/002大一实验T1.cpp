#include <iostream>
using namespace std;
void runnian(int year,int m) {
	int r=0;
	if(year%100!=0&&year%4==0||year%400==0)
		r++;
	switch(m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			cout<<"该月有31天";
			break;
		case 2: {
			
			if(r==0)
				cout<<"该月有28天";
			else if(r!=0)
				cout<<"该月有29天";
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
			cout<<"该月有30天";
			break;
	}
}
int main() {
	int year,m;
	cin>>year>>m;
	runnian(year,m);
	return 0;
}
