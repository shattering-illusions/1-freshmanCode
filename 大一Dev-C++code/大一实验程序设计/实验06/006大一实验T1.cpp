/*
设计人员类Person：
（1）数据成员：姓名string name、性别string sex。
（2）成员函数：构造函数、void dispInfo()（输出数据成员）；
从Person类公有派生学生类Student：
（1）新增数据成员：学号(string id)、专业(string major)。
（2）新增成员函数：构造函数、string getId()、string getMajor()、void dispInfo()（输出所有数据成员）。
实现两个类，并编写主函数测试父类和子类之间的函数同名隐藏特性。
提示：string类是C++的标准类，可以用来处理字符串信息，给字符串处理带来巨大的方便。使用方法请参看教材
*/
#include<iostream>
#include<string>

using namespace std;
class Person
{
	private:
		string name;
		string sex;
	public:
		Person(string name ,string sex)
		{
			this->name=name;
			this->sex=sex;
		}
		void dispInfo () const ;
};
void Person::dispInfo() const
{
	cout<<"Name :"<<name<<endl;
	cout<<"Sex  :"<<sex<<endl;
}

class Student : public Person
{
	private:
		string id,major;
	public:
		Student(string name ,string sex ,string id,string major):Person(name,sex),id(id),major(major)
		{
		};
		string getId() const
		{
			return id;
		}
		string getMajor() const
		{
			return major;
		}
		void dispInfo() const ;
};
void Student::dispInfo()const
{
	this->Person::dispInfo();
	cout<<"Id   :"<<id<<endl;
	cout<<"major:"<<major<<endl;
}
int main()
{
	string name,sex,name2,sex2,id,major;
	cout<<"Please enter the first one's name :"<<endl;
	getline(cin,name);
	cout<<"Please enter the first one's sex  :"<<endl;
	cin>>sex;
	Person firstPerson(name,sex);
	cout<<"----- The first information.  -----"<<endl;
	firstPerson.dispInfo();
	cout<<"Please enter the first second student's name sex id and major:"<<endl;
	cin>>name2>>sex2>>id>>major;
	Student secondStudent(name2,sex2,id,major);
	cout<<"----- The second information. -----"<<endl;
	secondStudent.dispInfo();
	return 0;
}
