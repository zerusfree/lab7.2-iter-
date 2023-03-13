#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2(iter).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab72itertest
{
	TEST_CLASS(lab72itertest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

            int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
            {
                a[i] = new int[n];
                for (int j = 0; j < n; j++)
                {
                    a[i][j] = n - j;
                }
            }

            Sort(a, n);

            Assert::AreEqual(a[0][0], 3);
            Assert::AreEqual(a[0][1], 2);
            Assert::AreEqual(a[0][2], 1);
            Assert::AreEqual(a[1][0], 3);
            Assert::AreEqual(a[1][1], 2);
            Assert::AreEqual(a[1][2], 1);
            Assert::AreEqual(a[2][0], 3);
            Assert::AreEqual(a[2][1], 2);
            Assert::AreEqual(a[2][2], 1);

            for (int i = 0; i < n; i++)
            {
                delete[] a[i];
            }
            delete[] a;
		}
	};
}
