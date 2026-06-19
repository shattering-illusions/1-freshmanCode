#include<iostream>
using namespace std;
int numberOfDaysInYear(int year)
{
	int day;
	return day=(year%4==0&&year%100!=0||year%400==0)?366:365;
}
int main()
{
	for(int i=2015;i<2026;i++)
	cout<<i<<":"<<numberOfDaysInYear(i)<<endl;
	return 0;
}
