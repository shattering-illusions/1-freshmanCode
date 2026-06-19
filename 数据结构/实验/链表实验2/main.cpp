#include <iostream>
#include"linkedList.h"

using namespace std;

int main() 
{
	//T1
	/*Queue T1_L1, T1_L2, T1_L3, T1_L4, T1_L5, T1_L6;

	cout << "请输入第一题的测试数据" << endl;
	T1_L1.input(15);
	T1_L1.split(T1_L3, T1_L4);
	cout << "原表为：";
	T1_L1.display();
	cout << "奇数表为：";
	T1_L3.display();
	cout << "偶数表为：";
	T1_L4.display();


	T1_L2.input(10);
	T1_L2.split(T1_L5, T1_L6);
	cout << "原表为：";
	T1_L2.display();
	cout << "奇数表为：";
	T1_L5.display();
	cout << "偶数表为：";
	T1_L6.display();

	//T2
	Queue T2_L1, T2_L2, T2_L3, T2_L4, T2_L5, T2_L6, T2_L7, T2_L8;

	cout << "请输入第二题的测试数据" << endl;
	T2_L1.input(10);

	T2_L2.input(13);

	T2_L3.input(8);

	T2_L4.input(10);

	T2_L1.getTheSame(T2_L2, T2_L6);
	T2_L3.getTheSame(T2_L1, T2_L7);
	T2_L4.getTheSame(T2_L5, T2_L8);

	cout << "三组测试数据的重复元素为：" << endl;
	T2_L6.display();
	T2_L7.display();
	T2_L8.display();

	//T3
	Queue T3_L1, T3_L2, T3_L3;

	cout << "请输入第三题的测试数据" << endl;
	T3_L1.input(9);
	T3_L1.deleteTheSame();
	cout << "去重后，表为：" << endl;
	T3_L1.display();

	T3_L2.input(17);
	T3_L2.deleteTheSame();
	cout << "去重后，表为：" << endl;
	T3_L2.display();

	T3_L3.input(15);
	T3_L3.deleteTheSame();
	cout << "去重后，表为：" << endl;
	T3_L3.display();*/

	//T4
	Queue T4_L1, T4_L2, T4_L3, T4_L4, T4_L5, T4_L6;

	cout << "请输入第四题的测试数据" << endl;
	T4_L1.input(10);
	T4_L2.input(13);
	T4_L1.mergeUnique(T4_L2);
	cout << "合并后表为：" << endl;
	T4_L1.display();

	T4_L3.input(10);
	T4_L4.input(8);
	T4_L3.mergeUnique(T4_L4);
	cout << "合并后表为：" << endl;
	T4_L3.display();

	T4_L6.input(10);
	T4_L5.mergeUnique(T4_L6);
	cout << "合并后表为：" << endl;
	T4_L5.display();

	//T5
	Queue T5_L;

	cout << "请输入第五题的测试数据" << endl;
	T5_L.input(10);
	cout << T5_L.findLastKNode(4);

	return 0;
}
