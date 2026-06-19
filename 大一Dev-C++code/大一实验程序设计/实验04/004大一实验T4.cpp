#include<iostream>
using namespace std;
int main()
{
	int i,ws=0;
	cin>>i;
	for(int m=i;m>=1;m/=10)
		ws++;
	char a[ws+1];
	for(int zz=0;i>=1;zz++,i/=10)
		a[ws-zz-1]=i%10+'0';
	for(int zzz=0;a[zzz]!='\0';zzz++)
		cout<<a[zzz];
	return 0;
}
