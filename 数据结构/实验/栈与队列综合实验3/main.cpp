#include<iostream>
#include"seqstack.h"
#include"SeqQueue.h"
#include"seqList.h"
#include"LinkStack.h"

using namespace std;

int main()
{
	//T1
	cout << "第一题结果为：" << endl;
	char s1[] = "{[](){}}";
	char s2[] = "{[(})]";
	whetherMatch(s1) ? cout << "s1匹配"<<endl : cout << "s1不匹配"<<endl;
	whetherMatch(s2) ? cout << "s2匹配"<<endl : cout << "s2不匹配"<<endl;

	//T2
	cout << "第二题结果为：" << endl;
	findAll(5);
	findAll(10);

	//T3  利用队列
	cout << "第三题结果为：" << endl;
	josephus(9,2,1);
	josephus(6,5,1);
	josephus(11,3,2);
	//T4  利用顺序表
	cout << "第四题结果为：" << endl;
	josephusLoop(9, 2, 1);
	josephusLoop(6, 5, 1);
	josephusLoop(11, 3, 2);

}