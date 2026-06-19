#include<iostream>
#include<cstdlib>
using namespace std;

int rowsum(int arr[4][4], int row)
{
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        sum += arr[row][i];
    }

    if (sum == 0)
    {
        return 0;
    }

    else if (sum == 4)
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

int columnsum(int arr[4][4], int column)
{
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        sum += arr[i][column];
    }

    if (sum == 0)
    {
        return 0;
    }

    else if (sum == 4)
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

int diagonalsum1(int arr[4][4])
{
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        sum += arr[i][i];
    }

    if (sum == 0)
    {
        return 0;
    }

    else if (sum == 4)
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

int diagonalsum2(int arr[4][4])
{
    int sum = 0;

    for (int i = 3; i >= 0; i--)
    {
        sum += arr[i][3 - i];
    }

    if (sum == 0)
    {
        return 0;
    }

    else if (sum == 4)
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

int main()
{
    int arr[4][4];
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (rowsum(arr, i) == 0 || rowsum(arr, i) == 1)
        {
            cout << "All " << rowsum(arr, i) << "'s on row " << i << endl;
            count1++;
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (columnsum(arr, i) == 0 || columnsum(arr, i) == 1)
        {
            cout << "All " << columnsum(arr, i) << "'s on column " << i << endl;
            count2++;
        }
    }
    
    if (diagonalsum1(arr) == 0 || diagonalsum1(arr) == 1)
    {
        cout << "All " << diagonalsum1(arr) << "'s on major diagonal" << endl;
        count3++;
    }

    if (diagonalsum2(arr) == 0 || diagonalsum2(arr) == 1)
    {
        cout << "All " << diagonalsum2(arr) << "'s on sub-diagonal" << endl;
        count4++;
    }
    
    if (count1 == 0)
    {
        cout << "No same numbers on the same row" << endl;
    }
    
    if (count2 == 0)
    {
        cout << "No same numbers on the same column" << endl;
    }
    
    if (count3 == 0)
    {
        cout << "No same numbers on the same diagonal" << endl;
    }
    
    if (count4 == 0)
    {
        cout << "No same numbers on the same subdiagonal" << endl;
    }

    return 0;
}