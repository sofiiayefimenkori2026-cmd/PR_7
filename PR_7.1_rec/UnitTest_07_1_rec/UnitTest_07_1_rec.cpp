#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_7.1_rec/PR_7.1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest071rec
{
    TEST_CLASS(UnitTest071rec)
    {
    public:
        TEST_METHOD(TestCalcRows)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** a = new int*[rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            a[0][0] = 4;  a[0][1] = 6;  a[0][2] = 7;
            a[1][0] = 8;  a[1][1] = 9;  a[1][2] = 10;
            a[2][0] = 12; a[2][1] = 13; a[2][2] = 14;

            int S = 0;
            int k = 0;
            CalcRows(a, rowCount, colCount, 0, S, k);

            Assert::AreEqual(50, S);
            Assert::AreEqual(5, k);
            Assert::AreEqual(0, a[0][1]);
            Assert::AreEqual(0, a[1][0]);
            Assert::AreEqual(4, a[0][0]);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}
