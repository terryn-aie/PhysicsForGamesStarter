// If needed, include your precompiled headers here:
#include "pch.h"
#include "CppUnitTest.h"
#include <stack>
#include "tracker.h"
#include "tbinarytree.h"

/*
* Renaming TBinaryTree<T>
* =========================
*
* If you did not name your binary tree as TBinaryTree, uncomment
* the typedef below and replace the second half with your type.
*
* For example, if you created a SBinTree<T>, it should read as follows...
*
* template<typename T>
* using TBinaryTree = SBinTree<T>;
*
* If you need to do this, you can uncomment and modify the lines below:
*/

//template<typename T>
//using TBinaryTree = TBinaryTree<T>;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace aiestd_test
{
	template <typename T>
	bool ValidateTreeByVertex(const typename TBinaryTree<T>::Vertex& startVertex)
	{
		std::stack<const TBinaryTree<T>::Vertex*> todo;

		const TBinaryTree<T>::Vertex* current = &startVertex;
		const T* prevValue = nullptr;

		while (current != nullptr && todo.empty())
		{
			// go as far left as possible
			while (current != nullptr)
			{
				todo.push(current);
				current = current->left;
			}

			current = todo.top();
			todo.pop();

			if (prevValue != nullptr &&
				*prevValue > current->data)
			{
				return false;
			}

			prevValue = &current->data;

			current = current->right;
		}

		return true;
	}

	TEST_CLASS(binaryTreeTests)
	{
	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			Tracker::Reset();
		}

		TEST_METHOD(ctor)
		{
			TBinaryTree<Tracker> tree;
		}

		TEST_METHOD(insert)
		{
			TBinaryTree<Tracker> tree;
			int trackerNum = Tracker::Count();
			tree.Insert(Tracker(4));
			Assert::AreEqual(trackerNum + 1, Tracker::Count(), L"Incorrect number of trackers generated.");

			tree.Insert(Tracker(2));
			Assert::AreEqual(trackerNum + 2, Tracker::Count(), L"Incorrect number of trackers generated.");

			tree.Insert(Tracker(6));
			Assert::AreEqual(trackerNum + 3, Tracker::Count(), L"Incorrect number of trackers generated.");
		}

		TEST_METHOD(search_ref)
		{
			TBinaryTree<int> tree;
			tree.Insert(4);
			tree.Insert(2);
			tree.Insert(6);
			tree.Insert(8);
			tree.Insert(5);

			TBinaryTree<int>::Vertex* nullVertex = nullptr;
			TBinaryTree<int>::Vertex* temp = nullptr;

			tree.Search(4, temp);
			Assert::AreEqual(4, temp->data);
			Assert::IsNotNull(temp->left);
			Assert::IsNotNull(temp->right);
			Assert::AreEqual(2, temp->left->data, L"Unexpected value");
			Assert::AreEqual(6, temp->right->data, L"Unexpected value");

			tree.Search(2, temp);
			Assert::AreEqual(2, temp->data);
			Assert::IsNull(temp->left);
			Assert::IsNull(temp->right);

			tree.Search(6, temp);
			Assert::AreEqual(6, temp->data);
			Assert::IsNotNull(temp->left);
			Assert::IsNotNull(temp->right);
			Assert::AreEqual(5, temp->left->data, L"Unexpected value");
			Assert::AreEqual(8, temp->right->data, L"Unexpected value");

			tree.Search(8, temp);
			Assert::AreEqual(8, temp->data);
			Assert::IsNull(temp->left);
			Assert::IsNull(temp->right);
		}
	};
}
