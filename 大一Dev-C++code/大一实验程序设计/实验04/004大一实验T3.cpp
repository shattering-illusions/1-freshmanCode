#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a;
	getline(cin,a);
	int words[26]={0};
	int n=a.length();
	for(int i=0;i<n;i++)
		if(a[i]>=97&&a[i]<=122)
			a[i]-=32;
	for(int i=0;i<n;i++)
	{
		words[a[i]-65]++;
	}
	for(int i=0;i<26;i++)
	{
		if(words[i]!=0)
		{
			char s=i+97;
		cout<<s<<"出现了"<<words[i]<<"次\n";
		} 
	}
	return 0;
}
