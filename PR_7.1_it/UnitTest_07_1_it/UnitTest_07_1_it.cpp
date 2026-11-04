#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_7.1_it/PR_7.1.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest071it
{
    TEST_CLASS(UnitTest071it)
    {
    public:
        TEST_METHOD(TestCalc)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** a = new int*[rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            // Deterministic matrix:
            // a[0][0]=4  (0%3==0 && 0%3==0 -> excluded)
            // a[0][1]=6  (even, not both %3 -> satisfied)
            // a[0][2]=7  (odd -> excluded)
            // a[1][0]=8  (even, not both %3 -> satisfied)
            // a[1][1]=9  (odd -> excluded)
            // a[1][2]=10 (even, not both %3 -> satisfied)
            // a[2][0]=12 (even, not both %3 -> satisfied)
            // a[2][1]=13 (odd -> excluded)
            // a[2][2]=14 (even, not both %3 -> satisfied)
            a[0][0] = 4;  a[0][1] = 6;  a[0][2] = 7;
            a[1][0] = 8;  a[1][1] = 9;  a[1][2] = 10;
            a[2][0] = 12; a[2][1] = 13; a[2][2] = 14;

            int S = 0;
            int k = 0;
            Calc(a, rowCount, colCount, S, k);

            // S = 6 + 8 + 10 + 12 + 14 = 50
            // k = 5
            Assert::AreEqual(50, S);
            Assert::AreEqual(5, k);
            Assert::AreEqual(0, a[0][1]);
            Assert::AreEqual(0, a[1][0]);
            Assert::AreEqual(4, a[0][0]); // excluded, unchanged

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}
