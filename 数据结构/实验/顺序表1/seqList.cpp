#include "seqList.h";

#include<iostream>;

#include<iomanip>;

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
		return rangeError;
	x = data[i - 1]; 
	return success;
}
errorCode seqList::insert(const int i, const elementType x)	//向该位置插入元素，其他后移
{
	if (count == maxlen)
		return overflow;
	if (i <= 0 || i > count+1)
		return rangeError;
	for (int j = count; j >= i; j--)
		data[j] = data[j - 1];
	data[i-1] = x;
	count++;
	return success;
}

errorCode seqList::deleteElement(const int i)	//删除该位置元素
{
	if (count == 0)
		return underflow;
	if (i <= 0 || i > count)
		return rangeError;
	for (int j = i; j < count ; j++)
		data[j-1] = data[j];
	count--;
	return success;
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
	return success;
}

void seqList::display()	//输出该表
{
	cout << endl;
	if (count == 0)
		cout << "NULL"<<endl;//空表输出NULL
	for (int i = 0; i < count; i++)//非空则循环输出
	{
		cout <<setw(5)<< data[i];
		if ((i+1) % 5 == 0 && i != 0)
			cout << endl;

	}
	cout << endl;
}

errorCode seqList::seqInsert(const elementType x)	// T1--顺序插入
{
	
	if (count == 0)			//表为空
	{
		this->insert(1, x);
		return success;
	}
	
	if (count == maxlen)	//表满
	{
		return overflow;
	}

	
	for (int i = 0; i < count; i++)
	{
		if (x <= data[i])
		{
			this->insert(i+1, x);
			return success;
		}
	}

	if (x > data[count - 1])
	{
		this->insert(count + 1, x);
		return success;
	}

}

void seqList::clean()	//清空该表
{
	count = 0;
}

errorCode seqList::split( seqList &S)	// 分离奇偶
{
	for (int i = 0; i < count;)
	{
		if (data[i] % 2 == 0)
		{
			S.insert(S.length()+1, data[i]);
			this->deleteElement(i + 1);
		}
		else
			i++;
	}

	cout << "奇数表为：" << endl;
	this->display();
	cout << "偶数表为：" << endl;
	S.display();
	return success;
}

errorCode seqList::findTheSame( seqList  &S1, seqList  &S2)	//找出相同元素
{
	S2.clean();
	for (int l = 0,r=0; l < count&&r<S1.length();)
	{
		elementType mode;
		S1.getElement(r + 1, mode);
		if (data[l] < mode)
		{
			l++;
		}
		else if (data[l] > mode)
		{
			r++;
		}
		else if (data[l] == mode)
		{
			S2.insert(S2.length() + 1, mode);
			l++;
			r++;
		}
		S2.deleteTheSame1();
	}

	return success;
}

/*errorCode seqList::deleteTheSame()	//删除单表的重复元素
{
	int num = 0;
	for (int left = 0; left < count-1; left++)
	{
		while (data[left+1]==data[left])
		{
			if (left + 1 == count)
				break;
			num += count - left - 2;
			deleteElement(left + 2);
		}
	}
	cout << "本次移动次数为" << num << endl;
	return success;
}*/
errorCode seqList::deleteTheSame1()	//删除单表的重复元素
{
	//int num = 0;
	for (int left = 0; left < count - 1; left++)
	{
		while (data[left + 1] == data[left])
		{
			if (left + 1 == count)
				break;
			//num += count - left - 2;
			deleteElement(left + 2);
		}
	}
	//cout << "本次移动次数为" << num << endl;
	return success;
}
errorCode seqList::deleteTheSame()//t4
{
	if (count <= 1)
		return success;

	int num = 0;
	int i = 0;            
	for (int j = 1; j < count; j++)
	{
		if (data[j] != data[i])
		{
			i++;
			if (i != j)        
			{
				data[i] = data[j];
				num++;  // 统计移动次数
			}
		}
	}
	count = i + 1;             // 删掉后面重复
	cout << "本次移动次数为" << num << endl;
	return success;
}