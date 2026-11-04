// PR_7.2.rec.cpp
// Єфіменко Софія
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 7
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo);
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int colCount, int colNo);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo);
void MinRow(int** a, const int rowNo, const int colCount, int colNo, int& min);
void MaxMinRows(int** a, const int rowCount, const int colCount, int rowNo, int& max);
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

    CreateRows(a, k, n, Low, High, 0);
    cout << "Matrix (" << k << "x" << n << "):" << endl;
    PrintRows(a, k, n, 0);

    int maxMin = MaxMin(a, k, n);
    cout << "Max of row minimums = " << maxMin << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
#endif

void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
        CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, colCount, Low, High, 0);
    if (rowNo < rowCount - 1)
        CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << setw(6) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

void MinRow(int** a, const int rowNo, const int colCount, int colNo, int& min)
{
    if (a[rowNo][colNo] < min)
        min = a[rowNo][colNo];
    if (colNo < colCount - 1)
        MinRow(a, rowNo, colCount, colNo + 1, min);
}

void MaxMinRows(int** a, const int rowCount, const int colCount, int rowNo, int& max)
{
    int min = a[rowNo][0];
    MinRow(a, rowNo, colCount, 1, min);
    if (rowNo == 0)
        max = min;
    if (min > max)
        max = min;
    if (rowNo < rowCount - 1)
        MaxMinRows(a, rowCount, colCount, rowNo + 1, max);
}

int MaxMin(int** a, const int rowCount, const int colCount)
{
    int max;
    MaxMinRows(a, rowCount, colCount, 0, max);
    return max;
}
