#include<iostream>
using namespace std;
void pdID(char id[]);
int main()
{
	char id[999];
	cin>>id;
	pdID(id);
	return 0; 
}
void pdID(char id[])
{
			//验证长度。 
	int length=0;
	for(int i=0;id[i]!='\0';i++)
		length++;
	if(length!=18)
	{
		cout<<"无效";
		return;
	}
			//验证是否为数字或X 
	int pd1=0;
	for(int i=0;i<18;i++)
	{
		if(id[i]<'0'&&i<17||id[i]>'9'&&i<17)
			pd1++;
		else if(id[i]!='x'&&id[i]!='X'&&id[i]>'9'||id[i]<'0'&&id[i]!='x'&&id[i]!='X')
			pd1++;	
	}
	if(pd1!=0)
	{
		cout<<"无效";
		return;
	}
			//验证年月 
	int year=(id[6]-'0')*1000+(id[7]-'0')*100+(id[8]-'0')*10+(id[9]-'0');
	if(year>2025)
	{
		cout<<"无效";
		return;
	}
	if(id[11]=='2'&&id[12]=='2'&&id[13]=='9')
	{
		if(year%400==0||year%100!=0&&year%4==0)
			pd1=0;
		else
			pd1++;
	}
	if(pd1!=0)
	{
		cout<<"无效";
		return;
	}
			//验证校验码。
	char jym=id[17];
	int mode;
	int sum=(id[0]-'0')*7+(id[1]-'0')*9+(id[2]-'0')*10+(id[3]-'0')*5;
	sum=sum+(id[4]-'0')*8+(id[5]-'0')*4+(id[6]-'0')*2+(id[7]-'0')*1;
	sum=sum+(id[8]-'0')*6+(id[9]-'0')*3+(id[10]-'0')*7+(id[11]-'0')*9+(id[12]-'0')*10;
	sum=sum+(id[13]-'0')*5+(id[14]-'0')*8+(id[15]-'0')*4+(id[16]-'0')*2;
	mode=sum%11;
	pd1=0;
	switch(mode)
	{
		case 0:
			if(jym!='1')
			{
				cout<<"无效";
				return;
			}
			break;
		case 1:
			if(jym!='0')
			{
				cout<<"无效";
				return;
			}
			break;
		case 2:
			if(jym!='x'&&jym!='X')
			{
				cout<<"无效";
				return;
			}
			break;
		case 3:
			if(jym!='9')
			{
				cout<<"无效";
				return;
			}
			break;
		case 4:
			if(jym!='8')
			{
				cout<<"无效";
				return;
			}
			break;
		case 5:
			if(jym!='7')
			{
				cout<<"无效";
				return;
			}
			break;
		case 6:
			if(jym!='6')
			{
				cout<<"无效";
				return;
			}
			break;
		case 7:
			if(jym!='5')
			{
				cout<<"无效";
				return;
			}
			break;
		case 8:
			if(jym!='4')
			{
				cout<<"无效";
				return;
			}
			break;
		case 9:
			if(jym!='3')
			{
				cout<<"无效";
				return;
			}
			break;
		case 10:
			if(jym!='2')
			{
				cout<<"无效";
				return;
			}
			break;	 
	}
	cout<<"有效";
}
