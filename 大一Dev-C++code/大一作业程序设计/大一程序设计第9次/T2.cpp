#include<iostream>
#include<string>
using namespace std;
int* count(const string& s);
int main()
{
	string s;
	getline(cin,s);
	int *p=count(s);
	for(int i=0;i<10;i++)
	cout<<i<<":"<<p[i]<<endl;
	delete []p;
	return 0;
}
int* count(const string& s)
{
	int *p=new int [10];
	for(int i= 0;i<10;i++)
		p[i]=0;
	int n=s.length();
	for(int i = 0;i<n;i++)
	{
		if(s.at(i)>='0'&&s.at(i)<='9')
			p[s.at(i)-'0']++;
	}
	return p; 
}
