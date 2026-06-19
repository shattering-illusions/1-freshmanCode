#include<iostream>
using namespace std;
/*编写函数void min_max_element(int *array, int n, int *minpos, int *maxpos) 
获取整型数组中最小和最大元素下标，如果有多个相同极值元素，返回最小下标
编写测试程序，输入数组元素个数及相应的数组元素，并输出数组中最小和最大元素下标。
输入样例：
8
2 4 4 5 7 8 8 2
输出样例：
min:0
max:5*/
void min_max_element(int *array, int n); 
int main()
{
	int size;
	cin>>size;
	int *p=new int[size];
	for(int i=0;i<size;i++)
		cin>>p[i];
	min_max_element(p,size);
	return 0;
}
void min_max_element(int *array, int n)
{
	int min=0,max=0;
	for(int i=0;i<n;i++)
	{
		if(*(array+i)<*(array+min))
			min=i;
		if(*(array+i)>*(array+max))
			max=i;
	}
	cout<<"min:"<<min<<endl<<"max:"<<max;
}
