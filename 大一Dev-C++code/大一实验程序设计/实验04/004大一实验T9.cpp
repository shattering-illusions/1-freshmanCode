#include<iostream>
using namespace std;
int main()
{
	int m,n;
	cout<<"你想创建带有几个整数的数组。"<<endl;
	cin>>m;
	int *p=NULL;
	p = new int[m];
	cout<<"输入"<<m<<"个整数\n";
	for(int i =0;i<m;i++)
		cin>>*(p+i);
	cout<<"输入你还想输入整数的个数。"<<endl;
	cin>>n;
	int *pp=NULL;
	pp = new int[m+n];
	for(int i=0;i<m;i++)
		pp[i]=p[i];
	delete [] p;
	cout<<"输入这"<<n<<"个整数"<<endl;
	for(int i=m;i<m+n;i++)
		cin>>pp[i];
	for(int i=0;i<m+n;i++)
		cout<<pp[i]<<" ";
	delete[]pp; 
	return 0;
}














