#include<iostream>
#include<cmath>
using namespace std;
const int SIZE = 3;
void sortColumns(const double m[ ][SIZE], double result[ ][SIZE]);
int main()
{
	double m[3][3],result[3][3];
	for(int i=0;i<SIZE;i++)
		for(int z=0;z<SIZE;z++)
			cin>>m[i][z];
	sortColumns(m,result);
	for(int i=0;i<SIZE;i++)
	{
		for(int z=0;z<SIZE;z++)
			cout<<result[i][z]<<"  ";
		cout<<endl;
	}		
	return 0;
}
void sortColumns(const double m[ ][SIZE], double result[ ][SIZE])
{
	
	for(int i=0 ;i<SIZE;++i)
	{
		for(int r=0;r<SIZE;++r)
		{
			result[i][r]=m[i][r]; 
		}	
	}
	for(int c =0;c<SIZE;c++)
	{
		double temp;
		int row2;
		for(int row=0;row<SIZE;++row)
		{
			temp=result[row][c];
			row2=row+1;
			for(;row2<SIZE;row2++)
			{
				if(temp>result[row2][c])
				{
					temp=result[row2][c];
					result[row2][c]=result[row][c];
					result[row][c]=temp;
				}
			}
		}
	}
}
