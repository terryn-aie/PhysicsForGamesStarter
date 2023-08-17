// please include pch.h at the TOP of the file if you need it
#include "pch.h"
#include "CppUnitTest.h"
#include "tracker.h"

#include "TList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*
* Renaming TList<T>
* =========================
*
* If you did not name your double-linked list as TList, uncomment
* the typedef below and replace the second half with your type.
*
* For example, if you created a SList<T>, it should read as follows...
*
* template<typename T>
* using TList = SList<T>
*
* If you need to do this, you can uncomment and modify the lines below:
*/

//template<typename T>
//using TList = TList<T>;

namespace aiestd_test
{
	TEST_CLASS(ListTests)
	{
		TEST_CLASS_INITIALIZE(Init)
		{
			Tracker::Reset();
		}

		// Validates that Push_Front Pushes objects to the Front
		//
		// Also requires Front() for validating the value of the object
		TEST_METHOD(Push_Front_and_Front)
		{
			TList<Tracker> trackers;
			int baseCount = Tracker::Count();

			trackers.Push_Front(Tracker(5));
			Assert::AreEqual(baseCount + 1, Tracker::Count(), L"Did not allocate a new instance of T for storage");
			Assert::AreEqual(Tracker(5), trackers.Front(), L"Value at Front was not as expected");

			trackers.Push_Front(Tracker(7));
			Assert::AreEqual(baseCount + 2, Tracker::Count(), L"Did not allocate a new instance of T for storage");
			Assert::AreEqual(Tracker(7), trackers.Front(), L"Value at Front was not as expected");
		}

		// Validates that objects Popped off the Front are destroyed
		TEST_METHOD(Pop_Front_and_Front)
		{
			TList<Tracker> trackers;
			int baseCount = Tracker::Count();
			trackers.Push_Front(Tracker(5));
			trackers.Pop_Front();
			Assert::AreEqual(baseCount, Tracker::Count(), L"Value was not destroyed after being Popped");

			trackers.Push_Front(Tracker(7));
			Assert::AreEqual(baseCount + 1, Tracker::Count(), L"Value was not added to the list - failed after Popping the last element prior");
			Assert::AreEqual(Tracker(7), trackers.Front(), L"Value at Front was not as expected");

			trackers.Push_Front(Tracker(9));
			Assert::AreEqual(baseCount + 2, Tracker::Count(), L"Value was not added to the list");
			Assert::AreEqual(Tracker(9), trackers.Front(), L"Value at Front was not as expected");

			trackers.Pop_Front();
			Assert::AreEqual(Tracker(7), trackers.Front(), L"Value at Front was not as expected");
			Assert::AreEqual(baseCount + 1, Tracker::Count(), L"Value was not destroyed after being Popped");
		}

		// Validates that Push_Back Pushes objects to the Back
		//
		// Also requires Back() for validating the value of the object
		TEST_METHOD(Push_Back_and_Back)
		{
			TList<Tracker> trackers;
			int baseCount = Tracker::Count();

			trackers.Push_Back(Tracker(5));
			Assert::AreEqual(baseCount + 1, Tracker::Count(), L"Did not allocate a new instance of T for storage");
			Assert::AreEqual(Tracker(5), trackers.Back(), L"Value at Back was not as expected");

			trackers.Push_Back(Tracker(7));
			Assert::AreEqual(baseCount + 2, Tracker::Count(), L"Did not allocate a new instance of T for storage");
			Assert::AreEqual(Tracker(7), trackers.Back(), L"Value at Back was not as expected");
		}

		// Validates that objects Popped off the Back are destroyed
		TEST_METHOD(Pop_Back_and_Back)
		{
			TList<Tracker> trackers;
			int baseCount = Tracker::Count();
			trackers.Push_Back(Tracker(5));
			trackers.Pop_Back();
			Assert::AreEqual(baseCount, Tracker::Count(), L"Value was not destroyed after being Popped");

			trackers.Push_Back(Tracker(7));
			Assert::AreEqual(baseCount + 1, Tracker::Count(), L"Value was not added to the list - failed after Popping the last element");
			Assert::AreEqual(Tracker(7), trackers.Back(), L"Value at Back was not as expected");

			trackers.Push_Back(Tracker(9));
			Assert::AreEqual(baseCount + 2, Tracker::Count(), L"Value was not added to the list");
			Assert::AreEqual(Tracker(9), trackers.Back(), L"Value at Back was not as expected");

			trackers.Pop_Back();
			Assert::AreEqual(Tracker(7), trackers.Back(), L"Value at Front was not as expected");
			Assert::AreEqual(baseCount + 1, Tracker::Count(), L"Value was not destroyed after being Popped");
		}

		TEST_METHOD(Push_Pop_Front_Back)
		{
			TList<Tracker> trackers;
			int baseCount = Tracker::Count();

			// Pushing and Popping from Back, resulting in an empty List
			trackers.Push_Back(Tracker(5));
			trackers.Pop_Back();
			Assert::AreEqual(baseCount, Tracker::Count(), L"Value was not destroyed after being Popped");

			// Validate front and back with 1 element
			trackers.Push_Back(Tracker(7));
			Assert::AreEqual(baseCount + 1, Tracker::Count(), L"Value was not added to the list - failed after Popping the last element");
			Assert::AreEqual(Tracker(7), trackers.Front(), L"Value at Front was not as expected");
			Assert::AreEqual(Tracker(7), trackers.Back(), L"Value at Back was not as expected");

			// Validate front and back with 2 elements
			trackers.Push_Back(Tracker(9));
			Assert::AreEqual(baseCount + 2, Tracker::Count(), L"Value was not added to the list");
			Assert::AreEqual(Tracker(7), trackers.Front(), L"Value at Front was not as expected");
			Assert::AreEqual(Tracker(9), trackers.Back(), L"Value at Back was not as expected");

			// Validate front and back with 1 element again
			trackers.Pop_Back();
			Assert::AreEqual(Tracker(7), trackers.Front(), L"Value at Front was not as expected");
			Assert::AreEqual(Tracker(7), trackers.Back(), L"Value at Back was not as expected");
			Assert::AreEqual(baseCount + 1, Tracker::Count(), L"Value was not destroyed after being Popped");

			// Clearing the list
			trackers.Pop_Back();
			// Ensure that all popped objects were destroyed
			Assert::AreEqual(baseCount, Tracker::Count(), L"Value was not destroyed after being Popped");

			// Pushing and Popping from Front
			trackers.Push_Front(Tracker(5));
			trackers.Pop_Front();
			// Ensure that all popped objects were destroyed
			Assert::AreEqual(baseCount, Tracker::Count(), L"Value was not destroyed after being Popped");

			// Push 1
			trackers.Push_Front(Tracker(7));
			Assert::AreEqual(baseCount + 1, Tracker::Count(), L"Value was not added to the list - failed after Popping the last element prior");
			Assert::AreEqual(Tracker(7), trackers.Front(), L"Value at Front was not as expected");
			Assert::AreEqual(Tracker(7), trackers.Back(), L"Value at Back was not as expected");

			// Push 1 more
			trackers.Push_Front(Tracker(9));
			Assert::AreEqual(baseCount + 2, Tracker::Count(), L"Value was not added to the list");
			Assert::AreEqual(Tracker(9), trackers.Front(), L"Value at Front was not as expected");
			Assert::AreEqual(Tracker(7), trackers.Back(), L"Value at Back was not as expected");

			// Pop 1
			trackers.Pop_Front();
			Assert::AreEqual(Tracker(7), trackers.Front(), L"Value at Front was not as expected");
			Assert::AreEqual(Tracker(7), trackers.Back(), L"Value at Back was not as expected");
			Assert::AreEqual(baseCount + 1, Tracker::Count(), L"Value was not destroyed after being Popped");
		}

		// validating that Front() has an overload for const-qualified
		TEST_METHOD(Front_Const)
		{
			TList<int> numbers;
			numbers.Push_Front(1);
			numbers.Push_Back(2);
			numbers.Push_Back(3);

			const TList<int>& numbersConst = numbers;
			Assert::AreEqual(1, numbers.Front(), L"Value at Front (const) was not as expected");
		}

		// validating that Back() has an overload for const-qualified
		TEST_METHOD(Back_Const)
		{
			TList<int> numbers;
			numbers.Push_Front(1);
			numbers.Push_Back(2);
			numbers.Push_Back(3);

			const TList<int>& numbersConst = numbers;
			Assert::AreEqual(3, numbers.Back(), L"Value at Back (const) was not as expected");
		}

		TEST_METHOD(Empty)
		{
			// default list should be Empty
			TList<int> nothing;
			TList<int>& nothingRef = nothing;
			Assert::IsTrue(nothingRef.Empty(), L"List was not Empty");

			// list should be Empty when you Push Back and Pop Back
			TList<int> clearedBack;
			clearedBack.Push_Back(5);
			clearedBack.Pop_Back();
			TList<int>& clearedRefB = clearedBack;
			Assert::IsTrue(clearedRefB.Empty(), L"List was not Empty");

			// list should be Empty when you Push Front and Pop Front
			TList<int> clearedFront;
			clearedFront.Push_Front(5);
			clearedFront.Pop_Front();
			TList<int>& clearedRefF = clearedFront;
			Assert::IsTrue(clearedRefF.Empty(), L"List was not Empty");
		}

		TEST_METHOD(Iterator_Begin_and_Deref)
		{
			TList<int> numbers;
			numbers.Push_Front(5);
			numbers.Push_Back(9);

			auto it = numbers.begin();
			Assert::AreEqual(5, *it, L"Iterator did not return the expected value at the Front");
		}

		TEST_METHOD(Iterator_PreIncrement)
		{
			TList<int> numbers;
			numbers.Push_Front(5);
			numbers.Push_Back(9);

			auto it = numbers.begin();
			Assert::AreEqual(9, *(++it), L"Iterator did not return the expected value");
		}

		TEST_METHOD(Iterator_PostIncrement)
		{
			TList<int> numbers;
			numbers.Push_Front(5);
			numbers.Push_Back(9);

			auto it = numbers.begin();
			Assert::AreEqual(5, *(it++), L"Iterator did not return the expected value");
			Assert::AreEqual(9, *(it), L"Iterator did not return the expected value");
		}

		TEST_METHOD(Iterator_PreDecrement)
		{
			TList<int> numbers;
			numbers.Push_Front(5);
			numbers.Push_Back(9);

			auto it = numbers.begin();
			++it;
			Assert::AreEqual(5, *(--it), L"Iterator did not return the expected value");
		}

		TEST_METHOD(Iterator_PostDecrement)
		{
			TList<int> numbers;
			numbers.Push_Front(5);
			numbers.Push_Back(9);

			auto it = numbers.begin();
			++it;
			Assert::AreEqual(9, *(it--), L"Iterator did not return the expected value");
			Assert::AreEqual(5, *(it), L"Iterator did not return the expected value");
		}

		TEST_METHOD(Iterator_End)
		{
			TList<int> numbers;
			numbers.Push_Front(4);
			numbers.Push_Back(9);

			auto it = numbers.begin();
			++it;
			++it;
			Assert::IsTrue(it == numbers.end(), L"Iterator did not return the expected value at the end");
		}

		TEST_METHOD(Iterator_Equality)
		{
			TList<int> numbers;
			numbers.Push_Front(5);
			numbers.Push_Back(9);

			auto itA = numbers.begin();
			Assert::IsTrue(itA == itA, L"Iterator was not considered equal to a copy of itself");

			auto itB = numbers.begin();
			Assert::IsTrue(itA == itB, L"Iterator was not considered equal to its equivalent");
		}

		TEST_METHOD(Iterator_Inequality)
		{
			TList<int> numbers;
			numbers.Push_Front(5);
			numbers.Push_Back(9);

			auto itbeginA = numbers.begin();
			Assert::IsFalse(itbeginA != itbeginA, L"Iterator was not considered inequal to a copy of itself");

			auto itbeginB = numbers.begin();
			Assert::IsFalse(itbeginA != itbeginB, L"Iterator was not considered inequal to its equivalent");

			auto itend = numbers.end();
			Assert::IsTrue(itbeginA != itend, L"Iterator was not considered inequal despite being different");
		}

		TEST_METHOD(Iterator_Range_based_For)
		{
			// list of test values
			TList<int> listNumbers;
			listNumbers.Push_Back(1);
			listNumbers.Push_Back(3);
			listNumbers.Push_Back(5);
			listNumbers.Push_Back(7);

			// array of test values
			int numbers[] = { 1,3,5,7 };
			auto it = listNumbers.begin();
			// tracks the number of times the loop runs
			size_t runs = 0;
			for (auto& num : numbers)
			{
				Assert::AreEqual(num, *it);
				++it;
				++runs;
			}

			Assert::AreEqual((size_t)4, runs, L"Iteration took more/less runs than expected");
		}

		TEST_METHOD(Insert)
		{
			int numbers[] = { 1,3,5,7 };

			TList<int> listNumbers;
			listNumbers.Push_Back(1);
			listNumbers.Push_Back(3);
			// - a five will be inserted -
			listNumbers.Push_Back(7);

			auto insertionIt = listNumbers.end();
			--insertionIt;

			listNumbers.Insert(insertionIt, 5);

			auto it = listNumbers.begin();
			for (auto& num : numbers)
			{
				Assert::AreEqual(num, *it);
				++it;
			}
		}

		TEST_METHOD(Size)
		{
			TList<int> emptyNumbers;
			Assert::AreEqual((size_t)0, emptyNumbers.Size());

			TList<int> listNumbers;
			listNumbers.Push_Back(1);
			listNumbers.Push_Back(2);
			listNumbers.Push_Back(3);
			listNumbers.Push_Back(4);

			Assert::AreEqual((size_t)4, listNumbers.Size());

			listNumbers.Pop_Back();

			Assert::AreEqual((size_t)3, listNumbers.Size());
		}
	};
}
