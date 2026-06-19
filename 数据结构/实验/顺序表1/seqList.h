#ifndef SEQLIST
#define SEQLIST
#include <iostream>
using namespace std;

enum errorCode {success,underflow,overflow,rangeError};
typedef int elementType;
const elementType maxlen = 99;
class seqList 
{
public:
	seqList();
	int length() const;
	errorCode getElement(const int i, elementType& x);
	int locate(const elementType x);
	errorCode insert(const int i, const elementType x);
	errorCode deleteElement(const int i);
	
	errorCode inPut(const int x);
	void display();

	errorCode seqInsert(const elementType x);			//T1
	errorCode split(seqList &S);						//T2
	errorCode findTheSame( seqList  &S1, seqList  &S2);	//T3
	errorCode deleteTheSame();							//T4
	errorCode deleteTheSame1();							


	void clean();

private:
	int count;
	elementType data[maxlen];
};

#endif 

