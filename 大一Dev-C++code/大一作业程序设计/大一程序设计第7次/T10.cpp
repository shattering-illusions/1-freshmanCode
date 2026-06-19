#include<iostream>
#include<cmath>
using namespace std;
void ftoa(double f,char s[])
{
	int n = 0;
	if((int)f == 0)
	{
		s[0]='0';
		n++;
	}
	else
	{
		for(int f1=(int)f,i=0;f1>=1;f1/=10,i++)
		{
			s[i]=f1%10+48; 
			n++;
		}
		for(int i=0;i<n/2;i++)
		{
			char temp = s[i];
			s[i] = s[n-1-i];
			s[n-1-i] = temp;
		}
	}
	double f1=f-(int)f;
	int f2=(int)(round(f1*1000000));
	for(int f3=f2,i=n+1;i<n+7;f3/=10,i++)
	{
		s[i]=f3%10+'0';
	}
	for(int m=n+1,pd=0;pd==0&&m<n+7;m++)
	{
		if(s[m]=='0')
			s[m]='\0';
		else
			pd++;
	}
	for(int i=0;i<3;i++)
	{
		char temp=s[n+1+i];
		s[n+1+i]=s[n+6-i];
		s[n+6-i]=temp;
	}
	s[n+7]='\0';
	if(s[n+1]=='\0')
		s[n]='\0';
	else
		s[n]='.';
	for(int i=0;s[i]!='\0';i++)
	{
		cout<<s[i]<<" ";
	}
}

int main()
{
	double f;
	cin>>f;
	char s[20];
	ftoa(f,s);
	return 0;
}
