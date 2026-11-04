#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_7.2_rec/PR_7.2.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest072rec
{
    TEST_CLASS(UnitTest072rec)
    {
    public:
        TEST_METHOD(TestMaxMin)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** a = new int*[rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

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
