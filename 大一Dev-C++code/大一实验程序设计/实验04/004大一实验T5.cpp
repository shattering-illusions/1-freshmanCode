#include<iostream>
#include<cstring>
using namespace std;
void chaR(char a[],char b[],int n);
int main()
{
	cout<<"请分别输入要插、被查的字符串和要插入的位置."<<endl; 
	char a[999],b[999];
	cin>>a>>b;
	int n;
	cin>>n;
	chaR(a,b,n);
	return 0;
}
void chaR(char a[],char b[],int n)
{
	int aLength=0;
	int bLength=0;
	for(int i=0;a[i]!='\0';i++)
		aLength++;
	for(int i=0;b[i]!='\0';i++)
		bLength++;	
	char b1[aLength+bLength];
	for(int i=0;i<n-1;i++)
	{
		b1[i]=b[i];
	}
	for(int i=n-1;i<n-1+aLength;i++)
	{
		b1[i]=a[i-n+1];
	}
	for(int i=n-1+aLength;i<aLength+bLength;i++)
	{
		b1[i]=b[i-aLength];
	}
	for(int i=0;b1[i]!='\0';i++)
		cout<<b1[i]; 
}
