#include<iostream>
#include<cstring>
using namespace std;
class MyString
{
private:
       char *p;
       int len;
public:
     MyString(char *p = NULL )
     {
     	this->p = new char[strlen(p)+1];
     	strcpy(this->p,p);
     	len = strlen(p);
	 }
     MyString(MyString &other)
     {
     	this->p = new char[strlen(other.p)+1]; 
     	strcpy(p,other.p);
     	len = other.len;
	 }
     ~MyString()
     {
     	delete [] p;
	 }
     void show()//Êä³ö×Ö·û´®
	{
		for(int i = 0 ;i<len ;i++)
			cout<< p[i];
	}
};
int main()
{
	char bb[99];
	cin.getline(bb,99);
	MyString st(bb);
	st.show();
	return 0;
}
