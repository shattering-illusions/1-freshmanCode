#include<iostream>
#include<string>
using namespace std;
void prefix(const string s1,  const string s2)
{
	string zzz;
	int n=0;
	int minl=min(s1.length(),s2.length()) ; 
	for(int i=0;i<minl;i++)
	{
		if(s1[i]==s2[i])
		{
			zzz+=s1.at(i);
			n++; 
		}
		else
		break; 
	}
	if(n==0)
	cout<<"无公共前缀";
	else
	cout<<"公共前缀是"<<zzz; 
}
int main()
{
	string si,sz;
	cin>>si>>sz;
	prefix(si,sz);
	return 0;
}
