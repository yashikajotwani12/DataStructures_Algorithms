#include <bits/stdc++.h>
using namespace std;

void spiral(int a[][100], int m, int n)
{
    int startrow = 0;
    int startcol = 0;
    int endrow = m - 1;
    int endcol = n - 1;

    //print it
    while (startrow <= endrow and startcol <= endcol)
    {
        // first col
        for (int i = startcol; i <= endcol; i++)
        {
            cout << a[startrow][i] << " ";
        }
        startrow++;
        for (int i = startrow; i <= endrow; i++)
        {
            cout << a[i][endcol] << " ";
        }
        endcol--;

        if (endrow > startrow)
        {
            for (int i = endcol; i >= startcol; i--)
            {
                cout << a[endrow][i] << " ";
            }
            endrow--;
        }
        if (endcol > startcol)
        {

            for (int i = endrow; i >= startrow; i--)
            {
                cout << a[i][startcol] << " ";
            }
            startcol++;
        }
    }
}

int main()
{
    int array[100][100];
    int m, n;
    cin >> m >> n;
    int val = 1;
    // iterating and printing
    for (int row = 0; row <= m - 1; row++)
    {
        for (int col = 0; col <= n - 1; col++)
        {
            array[row][col] = val;
            val = val + 1;
            cout << array[row][col] << " ";
        }
        cout << endl;
    }
    spiral(array, m, n);
    return 0;
}
