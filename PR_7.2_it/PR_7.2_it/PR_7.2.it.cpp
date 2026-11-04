// PR_7.2.it.cpp
// Єфіменко Софія
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 7
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int MaxMin(int** a, const int rowCount, const int colCount);

#if !defined(_WINDLL)
int main()
{
    srand((unsigned)time(NULL));
    const int Low = -10;
    const int High = 35;
    const int k = 4; // rowCount
    const int n = 5; // colCount

    int** a = new int*[k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    cout << "Matrix (" << k << "x" << n << "):" << endl;
    Print(a, k, n);

    int maxMin = MaxMin(a, k, n);
    cout << "Max of row minimums = " << maxMin << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
#endif

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(6) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int MaxMin(int** a, const int rowCount, const int colCount)
{
    int min, max;
    for (int i = 0; i < rowCount; i++)
    {
        min = a[i][0];
        for (int j = 1; j < colCount; j++)
            if (a[i][j] < min)
                min = a[i][j];
        if (i == 0)
            max = min;
        if (min > max)
            max = min;
    }
    return max;
}
