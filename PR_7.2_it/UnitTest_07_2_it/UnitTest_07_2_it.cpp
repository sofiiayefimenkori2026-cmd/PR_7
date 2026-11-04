#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_7.2_it/PR_7.2.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest072it
{
    TEST_CLASS(UnitTest072it)
    {
    public:
        TEST_METHOD(TestMaxMin)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** a = new int*[rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            // Row 0: { 10, 5, 20 }  -> min = 5
            // Row 1: { 15, 8, 12 }  -> min = 8
            // Row 2: { 3,  9, 14 }  -> min = 3
            // Max of minimums: max(5, 8, 3) = 8
            a[0][0] = 10; a[0][1] = 5; a[0][2] = 20;
            a[1][0] = 15; a[1][1] = 8; a[1][2] = 12;
            a[2][0] = 3;  a[2][1] = 9; a[2][2] = 14;

            int res = MaxMin(a, rowCount, colCount);
            Assert::AreEqual(8, res);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}
