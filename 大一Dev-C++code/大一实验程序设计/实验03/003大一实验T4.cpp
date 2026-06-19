#include<iostream>
#include<string>
using namespace std;
char strtran(char& s)
{
		if(s>=65&&s<=90)
		{
			s+=32;
		}
		else if(s>=97&&s<=122)
		{
			s-=32;
		}
	return s;
}
int main()
{
	string zz;
	getline(cin,zz);
	int length=zz.length();
	for(int i=0;i<length;i++)
	{
		strtran(zz.at(i));
	}
	cout<<zz;
	return 0;
}
