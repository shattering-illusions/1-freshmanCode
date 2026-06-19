#include<iostream>
#include<string>
using namespace std;
string swapCase(string& s)
{
	int length=s.length();
	for(int i=0;i<length;i++)
	{
		if(s[i]>=65&&s[i]<=90)
		{
			s[i]+=32;
		}
		else if(s[i]>=97&&s[i]<=122)
		{
			s[i]-=32;
		}
	}
	return s;
}
int main()
{
	string zzzz;
	getline(cin,zzzz);
	cout<<swapCase(zzzz);
	return 0;
}
