/*从第1题的Person类公有派生助教类Assistant,
增加数据成员：工资(double salary)，用虚基类方法设计出学生助教类StudentAssistant（多继承Assistant类和Student类）。
每个类中均重新设计构造函数、函数void dispInfo()用以输出该类对象全部数据成员。实现各个类并编写主函数测试之。*/
#include<iostream>
#include<string>
using namespace std;
//Base0
class Person
{
	private:
		string name;
		string sex;
	public:
		Person(string name,string sex )
		{
			this->name=name;
			this->sex=sex;
		}
		void dispInfo () const ;
};
void Person::dispInfo() const
{
	cout<<endl;
	cout<<"Name :"<<name<<endl;
	cout<<"Sex  :"<<sex<<endl;
}
//Base1
class Assistant :virtual public Person
{
	private:
		double salary;
	public:
		Assistant(string name ,string sex, double salary =0):Person(name,sex)
		{
			this->salary= salary;
		}
		void dispInfo() const ;
		double getSalary() const
		{
			return salary;
		}
};
void Assistant::dispInfo() const
{
	this->Person::dispInfo();
	cout<<"Salary:"<<salary<<endl;
}
//Base1
class Student : virtual public Person
{
	private:
		string id,major;
	public:
		Student(string name ,string sex ,string id ,string major ):Person(name,sex),id(id),major(major)
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
//Base2
class StudentAssistant : virtual public Student,virtual public Assistant
{
	public:
		StudentAssistant(string name ,string sex , string id ,string major ,double salary)
		:Person(name,sex),Student(name,sex,id,major),Assistant(name,sex,salary)
		{
			
		};
		void dispInfo() const
		{
			this->Student::dispInfo();
			cout<<"Salary:"<<this->getSalary()<<endl;
		}
};
int main()
{
	string name ,sex,id,major;
	double salary;
	cout<<"\nTry Person --------- Please enter name and sex:"<<endl;
	cin>>name>>sex;
	Person per(name,sex);
	per.dispInfo();
	cout<<"\nTry Student -------- Please enter name sex id and major:"<<endl;
	cin>>name>>sex>>id>>major;
	Student stu(name,sex,id,major);
	stu.dispInfo();
	cout<<"\nTry Assistant ------ Please enter name sex and salary:"<<endl;
	cin>>name>>sex >>salary;
	Assistant ass(name,sex,salary);
	ass.dispInfo();
	cout<<"\nTry StudentASsistant Please enter name sex id major and salaty:"<<endl;
	cin>>name>>sex>>id>>major>>salary;
	StudentAssistant stuAss(name,sex,id,major,salary);
	stuAss.dispInfo();
	return 0;
}
