#include<iostream>
#include<cmath>
using namespace std;
const int SIZE = 3;
bool isMarkovMatrix(const double m[][SIZE]);
int main()
{
	double m[3][3];
	for(int i=0;i<SIZE;i++)
		for(int z=0;z<SIZE;z++)
			cin>>m[i][z];
	if(isMarkovMatrix(m))
		cout<<"It is a Markov matrix.";
	else
		cout<<"It is not a Markov matrix.";
	return 0;
}
bool isMarkovMatrix(const double m[][SIZE])
{
	double sum=0.0;
	for(int i=0;i<SIZE;i++)
		for(int z=0;z<SIZE;z++)
			sum+=m[i][z];		
	return fmod(sum,1.0)==0.0;
}

