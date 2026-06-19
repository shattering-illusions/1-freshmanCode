#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int n=100,m=0;
	while(n<201) {
		if(n%5==0&&n%6!=0||n%5!=0&&n%6==0) {
			cout<<setw(4)<<n;
			m++;
		}
		if(m==10)
		{m-=10;
		cout<<endl;
		}
		n++;
		}
		return 0;
	}
