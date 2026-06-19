#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int n;
	cin>>n;
	if(n>15||n<1)
		cout<<"必须输入1到15的数";
	else {
		for(int m=1; m<=n; m++) {
			for(int i=1; i<=(n-m); i++)
				cout<<"    ";

			for(int i=m; i!=0; i--)
				cout<<right<<setw(4)<<i;

			for(int i=2; i<=m; i++)
				cout<<right<<setw(4)<<i;
			cout<<endl;
		}
	}
	return 0;
}
