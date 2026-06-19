#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class StopWatch
{
	public:
		void start()
		{
			start_time=clock();
		}
		void stop()
		{
			this->end_time=clock();
		}
		double get_start_time()
		{
			return start_time;
		}
		double get_end_time()
		{
			return end_time;
		}
		void getElapseTime() ;
	private:
		double start_time,end_time;
};
void StopWatch::getElapseTime() 
{
	cout<<(end_time-start_time);
}
void xuanze(int *ar,int size);
int main()
{
	srand(time(0));
	int *arr=new int[10000];
	for(int i=0;i<10000;i++)
		arr[i]=rand();
	StopWatch watch1;
	watch1.start();
	xuanze(arr,10000);
	watch1.stop();
	watch1.getElapseTime();
	delete [] arr;
	return 0;
}
void xuanze(int *ar,int size)
{
	for(int i=0;i<size-1;i++)
	{
		int min=i;
		for(int z=i+1;z<size;z++)
		{
			if(*(ar+min)>*(ar+z))
			{
				min=z;
			}
		}
		int temp=*(ar+min);
		*(ar+min)=*(ar+i);
		*(ar+i)=temp;
	}
	cout<<endl;
}
/*定义秒表类StopWatch，类包含：
（1）私有数据成员start_time和end_time，及相应的get函数；
（2）无参构造函数，利用当前时间初始化start_time；
（3）成员函数start( )重置start_time为当前时间（调用库函数clock()，使用方法请查资料）；
（4）成员函数stop( )设置end_time为当前时间；
（5）成员函数getElapseTime( )返回该秒表流逝的时间，以毫秒为单位。
编写测试程序，测量选择排序算法排序10000个随机整数消耗的时间（耗时与系统性能相关，本题将人工批阅）。
输出样例：
10*/ 
