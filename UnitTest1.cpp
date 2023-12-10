#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int sizeOfArray = 8;
			int testArr[sizeOfArray] = { 1, -4, 6, 0, 2, 3, 7, 2 };

			int C = 2;
			int expectedValue = 3;

			int realValue = countOfElemsGreaterThan(testArr, sizeOfArray, C);

			Assert::AreEqual(realValue, expectedValue);
		}
	};
}
