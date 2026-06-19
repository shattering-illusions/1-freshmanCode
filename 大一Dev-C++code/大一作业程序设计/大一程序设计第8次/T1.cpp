# include <iostream>
using namespace std;
const int SIZE = 4;
double sumColumn(const double m[][SIZE], int rowSize, int columnIndex);
int main()
{
    double array[3][4];
    for(int i=0;i<3;i++)
        for(int z=0;z<4;z++)
            cin>>array[i][z];
    int columIndex=0;
    for(int i=0;i<4;i++,columIndex++)
        cout<<i<<":"<<sumColumn(array,3,columIndex)<<"\n";
    return 0;
}
double sumColumn(const double m[][SIZE], int rowSize, int columnIndex)
{
    double sum = 0;
    for(int i = 0;i < rowSize;i++)
    {
        sum += m [i][columnIndex];
    }
    return sum;
}