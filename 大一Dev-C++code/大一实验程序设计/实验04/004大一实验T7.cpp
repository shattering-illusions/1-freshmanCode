#include<iostream>
#include<string>
using namespace std;
void pd(string a);
int main()
{
	string a;
	getline(cin,a);
	pd(a);
	return 0;
}
void pd(string a)
{
	int n=a.length();
	for(int i=0;i<n;i++)
		if(a[i]>=97&&a[i]<=122)
			a[i]-=32;
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<65||a[i]>90)
		{
			int t=a[i];
			for(int z=i;z<n-1;z++)
				a[z]=a[z+1];
			a[n-1]=t;
			j++;
		}
	}
	for(int i=0;i<(n-j)/2;i++)
	{
		if(a[i]!=a[n-j-i])
		{
			cout<<"No."; 
			return;
		}
	}
	cout<<"Yes.";
}











