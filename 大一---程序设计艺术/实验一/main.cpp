#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

void doTask1()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(rand() % 10);//生成0-9的随机数
	std::cout << "第一次遍历vector：" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)//第一次遍历vector
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	v.insert(v.begin(), rand() % 10);//插入随机数
	std::cout << "插入随机数后，第二次遍历vector：" << std::endl;
	for (auto it = v.begin(); it != v.end(); ++it)//第二次遍历vector
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	int randNum = rand() % 10;
	auto it = find(v.begin(), v.end(), randNum);
	if (it != v.end())
		std::cout << "找到了，该随机数为：" << *it << std::endl;
	else
		v.push_back(randNum);

	std::sort(v.begin(), v.end());//排序

	std::cout << "排序后，第三次遍历vector：" << std::endl;
	for (auto it = v.begin(); it != v.end(); ++it)//第三次遍历vector
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	v.pop_back();
	//v.erase(v.end());//删除最后的一个元素
	std::cout << "删除最后一个元素后，第四次遍历vector：" << std::endl;
	for (auto it = v.begin(); it != v.end(); ++it)//第四次遍历vector
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	v.clear();//清空vector

	std::list<int> l;
	for (int i = 0; i < 10; i++)
		l.list::push_back(rand() % 10);
	std::cout << "第一次遍历list：" << std::endl;
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)//第一次遍历list
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	l.list::push_front(rand()%10);		//插入随机数
	std::cout << "插入随机数后，第二次遍历list：" << std::endl;
	for (auto it = l.begin(); it != l.end(); ++it)//第二次遍历list
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	int randNum2 = rand() % 10;
	auto it2 = find(l.begin(), l.end(), randNum2);
	if (it2 != l.end())
		std::cout << "找到了，该随机数为：" << *it2 << std::endl;
	else
		l.push_back(randNum2);

	l.list::sort();//排序

	std::cout << "排序后，第三次遍历list：" << std::endl;
	for (auto it = l.begin(); it != l.end(); ++it)//第三次遍历list
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	l.pop_back();//删除最后的一个元素
	std::cout << "删除最后一个元素后，第四次遍历list：" << std::endl;
	for (auto it = l.begin(); it != l.end(); ++it)//第四次遍历list
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	l.clear();

}

void doTask2()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(rand() % 10);
	sort(v.begin(), v.end());//升序排序
	std::cout << "第一次遍历："<<std::endl;
	for (auto it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::reverse(v.begin(), v.end());//倒序
	std::cout << "第二次遍历：" << std::endl;
	for (auto it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " " ;
	std::cout << std::endl;

	int randNum = rand() % 10;
	auto it = find(v.begin(), v.end(), randNum);
	if (it != v.end())
		std::cout << "找到 " << *it << " 了" << std::endl;
	else
		std::cout << "没找到 " << *it << std::endl;

	std::cout << "最大的元素为：" << *max_element(v.begin(), v.end()) << std::endl;
	std::cout << "最小的元素为：" << *min_element(v.begin(), v.end()) << std::endl;

}

int main()
{
	std::srand(time(nullptr));
	std::cout << "------ 任务一 ------" << std::endl;
	doTask1();
	std::cout << "------ 任务二 ------" << std::endl;
	doTask2();

	return 0;
}