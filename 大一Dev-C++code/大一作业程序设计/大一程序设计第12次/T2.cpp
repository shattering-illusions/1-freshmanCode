#include <iostream>
#include <cstring> 
using namespace std;

class Person
{
	private:
		char *name;
		char sex;
		int age;
	public:
		Person(const char *_name,const char _sex,const int _age)
		{
			name=new char[strlen(_name)+1];
			strcpy(name,_name);
			sex=_sex;
			age=_age;
		}
		~Person()
		{
			delete[] name;
		}
		void printInfo() const;
};

class Student : public Person
{
	private:
		char *major,*name,sex;
		int grade,id,age;
	public:
		static int _id;
		Student(const char *_name,const char _sex,const int _age,const char *_major,const int _grade)
		:Person(_name,_sex,_age) 
		{
			major = new char[strlen(_major)+1];
			strcpy(major,_major);
			grade = _grade;
			id=_id++;
		}
		~Student()
		{
			delete [] major;
		}
		void printInfo() const;
};

void Person::printInfo() const
{
	cout<<"姓名："<<name<<endl;
	cout<<"性别："<<sex<<endl;
	cout<<"年龄："<<age<<endl;
}
int Student::_id=1;
void Student::printInfo() const
{
	cout<<"专业："<<major<<endl;
	cout<<"年级："<<grade<<endl;
	cout<<"学号："<<id<<endl;
}
int main() {
	char name[20], sex, major[50];
	int age, grade;
	
	cin >> name >> sex >> age;
    Person p(name, sex, age);

	cin >> name >> sex >> age >> major >> grade;
    Student s1(name, sex, age, major, grade);
    
	cin >> name >> sex >> age >> major >> grade;
	Student s2(name, sex, age, major, grade);
	
	p.printInfo();
    cout << endl;
    
    s1.printInfo();
    cout << endl;
    
    s2.Person::printInfo();
    s2.printInfo();

    return 0;
}
/*（1）设计人员类Person
数据成员：姓名、性别、年龄
成员函数：构造函数和void printInfo( )（用于输出数据成员）；
要求：姓名定义为char*，创建类对象时要利用构造函数new一个空间存放姓名，并用指针指向。
类对象生命期结束时，要利用析构函数释放空间。
（2）从Person类派生出学生类Student
新增数据成员：专业、年级、学号
新增成员函数：构造函数和void printInfo( )（输出数据成员）
要求：利用一个静态数据成员为类对象自动生存学号
实现两个类，并编写主函数测试父类和子类之间的同名函数隐藏特性，测试输出如下（编程结果须满足如下输出）：
输入样例：
张三 M 25
李四 F 22 计算机 2025
王五 M 20 软件工程 2025
输出样例：
姓名：张三
性别M
年龄：25

专业：计算机
年级：2025
学号：1

姓名：王五
性别：M
年龄：20
专业：软件工程
年级：2025
学号：2*/ 
