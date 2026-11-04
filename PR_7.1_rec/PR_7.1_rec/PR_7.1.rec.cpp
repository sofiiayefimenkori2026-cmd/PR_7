// PR_7.1.rec.cpp
// Єфіменко Софія
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 7 (рекурсивний спосіб)
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo);
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int colCount, int colNo);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo);
void Change(int** a, const int row1, const int row2, const int colCount, int j);
void Sort(int** a, const int rowCount, const int colCount, int i0, int i1);
void CalcRow(int** a, const int rowNo, const int colCount, int colNo, int& S, int& k);
void CalcRows(int** a, const int rowCount, const int colCount, int rowNo, int& S, int& k);

#if !defined(_WINDLL)
int main()
{
    srand((unsigned)time(NULL));
    const int Low = 4;
    const int High = 51;
    const int rowCount = 8;
    const int colCount = 5;

    int** R = new int*[rowCount];
    for (int i = 0; i < rowCount; i++)
        R[i] = new int[colCount];

    CreateRows(R, rowCount, colCount, Low, High, 0);
    cout << "Initial matrix R (8x5):" << endl;
    PrintRows(R, rowCount, colCount, 0);

    Sort(R, rowCount, colCount, 0, 0);
    cout << "Sorted matrix R (keys: col 0 asc, col 1 desc, col 2 desc):" << endl;
    PrintRows(R, rowCount, colCount, 0);

    int S = 0;
    int k = 0;
    CalcRows(R, rowCount, colCount, 0, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << "Modified matrix R (elements replaced by 0):" << endl;
    PrintRows(R, rowCount, colCount, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] R[i];
    delete[] R;

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
    cout << setw(5) << a[rowNo][colNo];
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

void Change(int** a, const int row1, const int row2, const int colCount, int j)
{
    int tmp = a[row1][j];
    a[row1][j] = a[row2][j];
    a[row2][j] = tmp;
    if (j < colCount - 1)
        Change(a, row1, row2, colCount, j + 1);
}

void Sort(int** a, const int rowCount, const int colCount, int i0, int i1)
{
    if ((a[i1][0] > a[i1 + 1][0])
        ||
        (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1])
        ||
        (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][2] < a[i1 + 1][2]))
    {
        Change(a, i1, i1 + 1, colCount, 0);
    }

    if (i1 < rowCount - i0 - 2)
        Sort(a, rowCount, colCount, i0, i1 + 1);
    else if (i0 < rowCount - 2)
        Sort(a, rowCount, colCount, i0 + 1, 0);
}

void CalcRow(int** a, const int rowNo, const int colCount, int colNo, int& S, int& k)
{
    if (!(a[rowNo][colNo] % 2 != 0 || (rowNo % 3 == 0 && colNo % 3 == 0)))
    {
        S += a[rowNo][colNo];
        k++;
        a[rowNo][colNo] = 0;
    }
    if (colNo < colCount - 1)
        CalcRow(a, rowNo, colCount, colNo + 1, S, k);
}

void CalcRows(int** a, const int rowCount, const int colCount, int rowNo, int& S, int& k)
{
    CalcRow(a, rowNo, colCount, 0, S, k);
    if (rowNo < rowCount - 1)
        CalcRows(a, rowCount, colCount, rowNo + 1, S, k);
}
