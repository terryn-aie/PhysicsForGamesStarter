#include "pch.h"
#include "CppUnitTest.h"

#include "TVector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace aiestdtest
{
	TEST_CLASS(aiestdtest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			TVector<int> numbers;
			numbers.Push_Back(5);

			Assert::AreEqual(5, numbers.Back(), L"Back was not the expected value!");
		}
	};
}
