#include "seqList.h"
#include<iostream>
#include<iomanip>

seqList::seqList()		//初始化
{
	count = 0;
}

int seqList::length()const	//取长度
{
	return count;
}

int seqList::locate(const elementType x)	//确定这个元素第一次出现在哪个位置，无则返回0
{
	for (int i = 0; i < count; i++)
		if (data[i] == x)
			return i+1;
	return 0;
}

errorCode seqList::getElement(const int i, elementType& x)	//取出对应位置的元素
{
	if (i <= 0 || i > count)
		return rangeError_code;
	x = data[i - 1]; 
	return success_code;
}
errorCode seqList::insert(const int i, const elementType x)	//向该位置插入元素，其他后移
{
	if (count == maxlen)
		return overflow_code;
	if (i <= 0 || i > count+1)
		return rangeError_code;
	for (int j = count; j >= i; j--)
		data[j] = data[j - 1];
	data[i-1] = x;
	count++;
	return success_code;
}

errorCode seqList::deleteElement(const int i)	//删除该位置元素
{
	if (count == 0)
		return underflow_code;
	if (i <= 0 || i > count)
		return rangeError_code;
	for (int j = i; j < count ; j++)
		data[j-1] = data[j];
	count--;
	return success_code;
}

errorCode seqList::inPut( int x)	//手动输入x个元素
{
	int i=0,mod;
	while (i < x)
	{
		cin >> mod;
		data[count++] = mod;
		i++;
	}
	return success_code;
}

void seqList::display()	//输出该表
{
	cout << endl;
	if (count == 0)
		cout << "NULL"<<endl;
	for (int i = 0; i < count; i++)
	{
		cout <<setw(5)<< data[i];
		if ((i+1) % 5 == 0 && i != 0)
			cout << endl;

	}
	cout << endl;
}

void josephusLoop(int n, int k, int m)
{
	seqList q;
	for (int i = 1; i <= n; i++)//把 1~n 编号入队
	{
		q.insert(i, i);
	}

	int mod = 0;

	while (q.length() > m && q.length() > 0)//删到人数只剩m
	{
		elementType x;
		q.getElement(1, x); // 取队头
		q.deleteElement(1);      // 出队
		mod++;          // 报数 +1
		if (mod == k)   //k淘汰
		{
			mod = 0;    // 重新从 1 开始报数
		}
		else
		{
			q.insert(q.length() + 1, x);//不淘汰，就插入队尾
		}
	}

	while (q.length() != 0)  //输出最后剩下的人
	{
		elementType x;
		q.getElement(1, x);
		q.deleteElement(1);
		cout << x << " ";
	}
	cout << endl;
}