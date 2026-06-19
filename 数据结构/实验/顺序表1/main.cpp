#include <iostream>
#include "seqList.h"

using namespace std;

int main()
{
	//T1
	/*cout << "开始测试第一题.\n请输入题目中的数组信息:" << endl;
	seqList S;
	S.inPut(10);
	//S.display();		
	S.seqInsert(25);
	S.seqInsert(85);
	S.seqInsert(110);
	S.seqInsert(8);
	S.display();
	
	//T2
	cout << "开始测试二题.\n请输入题目中的数组信息:" << endl;
	seqList T2_S1, T2_S2;
	seqList T2_S3, T2_S4;
	T2_S1.inPut(15);
	T2_S2.inPut(10);
	T2_S1.split(T2_S3);
	T2_S2.split(T2_S4);
	
	//T3
	cout << "开始测试三题.\n请输入题目中的数组信息:" << endl;
	seqList T3_S1, T3_S2, T3_S3, T3_S4, T3_S5, T3_S6, T3_S7, T3_S8;
	T3_S1.inPut(10);
	T3_S2.inPut(13);
	T3_S3.inPut(8);
	T3_S5.inPut(10);

	T3_S1.findTheSame(T3_S2, T3_S6);
	T3_S1.findTheSame(T3_S3, T3_S7);
	T3_S5.findTheSame(T3_S4, T3_S8);

	cout << "第一组重复元素为：" << endl;
	T3_S6.display();
	cout << "第二组重复元素为：" << endl;
	T3_S7.display();
	cout << "第三组重复元素为："<< endl;
	T3_S8.display();*/

	//T4
	cout << "开始测试第四题.\n请输入题目中的数组信息:" << endl;
	seqList T4_S1, T4_S2, T4_S3;

	T4_S1.inPut(9);
	T4_S1.deleteTheSame();
	T4_S1.display();

	T4_S2.inPut(17);
	T4_S2.deleteTheSame();
	T4_S2.display();
	
	T4_S3.inPut(15);
	T4_S3.deleteTheSame();
	T4_S3.display();
	

	return 0;
}



