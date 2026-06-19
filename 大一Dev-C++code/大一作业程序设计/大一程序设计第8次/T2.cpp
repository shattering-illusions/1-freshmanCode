# include <iostream>
using namespace std;
const  int SIZE = 4;
double sumMajorDiagonal(const double m[ ][SIZE]);
int main()
{
    double array[4][4];
    for(int i=0;i<4;i++)
        for(int z=0;z<4;z++)
            cin>>array[i][z];
    cout<<"sum:"<<sumMajorDiagonal(array);
    return 0;
}
double sumMajorDiagonal(const double m[][SIZE])
{
    int sum =0;
    for(int i=0;i<4;i++)
        sum+=m[i][i];
    return sum;
}