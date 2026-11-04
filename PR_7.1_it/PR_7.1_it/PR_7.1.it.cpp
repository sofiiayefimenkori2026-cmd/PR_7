// PR_7.1.it.cpp
// Єфіменко Софія
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 7 (ітераційний спосіб)
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

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

    Create(R, rowCount, colCount, Low, High);
    cout << "Initial matrix R (8x5):" << endl;
    Print(R, rowCount, colCount);

    Sort(R, rowCount, colCount);
    cout << "Sorted matrix R (keys: col 0 asc, col 1 desc, col 2 desc):" << endl;
    Print(R, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(R, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << "Modified matrix R (elements replaced by 0):" << endl;
    Print(R, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] R[i];
    delete[] R;

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
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
            if ((a[i1][0] > a[i1 + 1][0])
                ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1])
                ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][2] < a[i1 + 1][2]))
            {
                Change(a, i1, i1 + 1, colCount);
            }
}

void Change(int** a, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)
    {
        tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (!(a[i][j] % 2 != 0 || (i % 3 == 0 && j % 3 == 0)))
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
}
