#include<iostream>
using namespace std;
int countLetters(const char s[])
{
	int sum=0;
	for(int i=0;s[i]!='\0';++i)
	{
		if(s[i]>=65&&s[i]<=90||s[i]>=97&&s[i]<=122)
			sum+=1; 
	}
	return sum;
}
int main()
{
	char s[80];
	cin.getline(s,79,'\n'); 
	cout<<countLetters(s);
	return 0;
}

