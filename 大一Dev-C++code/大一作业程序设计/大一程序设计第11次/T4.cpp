#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    char id[11];   // 学号
    char *name;    // 姓名
    float math;    // 数学成绩
    float physics; // 物理成绩
    float english; // 英语成绩
    float total;   // 总成绩
public:
	~Student()
	{
		delete []name;
	}
    void setInfo(const char* _id, const char* _name, float _math, float _physics, float _english)
	{
		strcpy(id,_id);
		name = new char[strlen(_name)+1];
		strcpy(name,_name);
		math=_math;
		physics=_physics;
		english=_english;
		total=math+physics+english;	
    }
    float getTotal()
	{
        return total;
    }
    const char* getId()
	{
        return id;
    }
    const char* getName()
	{
    	return name;
    }
    void printInfo() {
        cout << "学号：" << id << endl;
        cout << "姓名：" << name << endl;
        cout << "数学成绩：" << math << endl;
        cout << "物理成绩：" << physics << endl;
        cout << "英语成绩：" << english << endl;
        cout << "总成绩：" << total << endl;
    }
};
int main() {
	const int SIZE = 3; 
    Student students[SIZE];
    char id[11], name[21];
    float math, physics, english;
    for(int i = 0; i < SIZE; i++)
    {
    	cin >> id;
    	cin >> name;
    	cin >> math >> physics >> english;
    	students[i].setInfo(id, name, math, physics, english);
	}
    //cout << "请输入查询学号：" << endl;
    cin >> id;
    // 输出成绩单
    cout << "总分成绩表：" << endl;
	for(int i=0;i<SIZE;i++)
	{
		cout<<students[i].getId()<<" "<<students[i].getName()<<": "<<students[i].getTotal()<<endl;
	}
    // 求出最高总分
    float maxTotal = students[0].getTotal();
	for(int i=1;i<SIZE;i++)
	{
		if(students[i].getTotal()>maxTotal)
			maxTotal=students[i].getTotal();
	}
    cout << "最高总分：" << maxTotal << endl;
    // 输出查询结果 
    cout << "查询结果：" << endl;
	for(int i=0;i<SIZE;i++)
	{
		if(strcmp(id,students[i].getId())==0)
			students[i].printInfo();
	}
    return 0;
}
