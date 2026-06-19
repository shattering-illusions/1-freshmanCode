#include<iostream>

using namespace std;
class Clock
{
	public:
		Clock(int hour=0,int minute = 0,int second =0)
		{
			this->hour=hour;
			this->minute=minute;
			this->second=second; 
		}
		void setTime(int h, int m, int s)
		{
			hour=h;
			minute=m;
			second=s;
		}
		void showTime()
		{
			cout<<hour<<":"<<minute<<":"<<second<<endl;
		}
		int interval(Clock &other)const;
	private:
		int hour,minute,second;
};
int Clock::interval(Clock &other)const
{
	int h=hour-other.hour;
	int m=minute-other.minute;
	int s=second-other.second;
	int sum=h*3600+m*60+s;
	return -sum;
}
int main()
{
	int h,m,s,h1,m1,s1;
	cin>>h>>m>>s>>h1>>m1>>s1;
	Clock clock_1,clock_2;
	clock_1.setTime(h,m,s);
	clock_2.setTime(h1,m1,s1);
	clock_1.showTime();
	clock_2.showTime();
	cout<<clock_1.interval(clock_2);
	return 0;
}
/*  设计一个时钟类Clock
（1）数据成员：时(int hour)，分(int minute)，秒(int second)；
（2）成员函数：
①构造函数Clock(int hour=0, int minute = 0, int second =0)，
②设置函数void setTime(int h, int m, int s)，
③显示时间函数void showTime()，
④计算本对象时刻与一给定时刻的间隔秒数函数int interval(int h, int m, int s)（形参也可以是Clock）。
编写主函数测试Clock类，输入两组时分秒，显示输入的时间及其间隔秒数。
输入样例：
0 1 2
3 4 5
输出样例：
0:1:2
3:4:5
10983   */
