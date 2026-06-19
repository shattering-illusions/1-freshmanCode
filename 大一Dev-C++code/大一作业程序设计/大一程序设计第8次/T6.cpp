# include <iostream>
using namespace std;
const int SIZE = 4;
void findRowColumn(int array[][SIZE]);
int main()
{
    int array[4][4];
    for(int i=0;i<4;i++)
        for(int z=0;z<4;z++)
            cin>>array[i][z];
    findRowColumn(array);
    return 0;
}
void findRowColumn(int array[][SIZE])
{
    int sumRow[4]={0},sumColumn[4]={0};
    for(int i=0;i<SIZE;i++)
        for(int zz=0;zz<SIZE;zz++)
        {
            if(array[i][zz]==1)
                sumRow[i]++;
            if(array[zz][i]==1)
                sumColumn[i]++;
        }
    int maxRow=0,maxColumn=0;
    for(int i=0;i<SIZE;i++)
    {
        if(sumRow[i]>sumRow[maxRow])
            maxRow=i;
        if(sumColumn[i]>sumColumn[maxColumn])
            maxColumn=i;
    }
    cout<<"数字1最多的行"<<maxRow<<endl;
    cout<<"数字1最多的列"<<maxColumn;
}
