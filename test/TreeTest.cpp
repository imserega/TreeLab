#include "pch.h"
#include "CppUnitTest.h"
#include "..\TreeLab\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeTest
{
	TEST_CLASS(TreeTest)
	{
	public:

		TEST_METHOD(BFT_TEST1)
		{
			Tree t;

			t.insert(5);//			5
			t.insert(3);//		3		6
			t.insert(2);//	 2	   4	   7
			t.insert(4);//
			t.insert(6);//
			t.insert(7);//

			Iterator* tree_BFT_iterator = t.create_bft_iterator();
			Assert::AreEqual(tree_BFT_iterator->next(), 5);
			Assert::AreEqual(tree_BFT_iterator->next(), 3);
			Assert::AreEqual(tree_BFT_iterator->next(), 6);
			Assert::AreEqual(tree_BFT_iterator->next(), 2);
			Assert::AreEqual(tree_BFT_iterator->next(), 4);
			Assert::AreEqual(tree_BFT_iterator->next(), 7);
		}

		TEST_METHOD(BFT_TEST2)
		{
			Tree t;

			t.insert(8);//			8
			t.insert(4);//		4		10
			t.insert(2);//	 2	   5  9    15
			t.insert(1);// 1   3		 13  16
			t.insert(3);//
			t.insert(10);//
			t.insert(9);//
			t.insert(15);//
			t.insert(13);//
			t.insert(16);//
			t.insert(5);//

			t.insert(6);

			Iterator* tree_BFT_iterator = t.create_bft_iterator();
			Assert::AreEqual(tree_BFT_iterator->next(), 8);
			Assert::AreEqual(tree_BFT_iterator->next(), 4);
			Assert::AreEqual(tree_BFT_iterator->next(), 10);
			Assert::AreEqual(tree_BFT_iterator->next(), 2);
			Assert::AreEqual(tree_BFT_iterator->next(), 5);
			Assert::AreEqual(tree_BFT_iterator->next(), 9);
			Assert::AreEqual(tree_BFT_iterator->next(), 15);
			Assert::AreEqual(tree_BFT_iterator->next(), 1);
			Assert::AreEqual(tree_BFT_iterator->next(), 3);
			Assert::AreEqual(tree_BFT_iterator->next(), 6);
			Assert::AreEqual(tree_BFT_iterator->next(), 13);
			Assert::AreEqual(tree_BFT_iterator->next(), 16);
		}


		TEST_METHOD(DFT_TEST1)
		{
			Tree t;

			t.insert(8);//			8
			t.insert(4);//		4		10
			t.insert(2);//	 2	   5  9    15
			t.insert(1);// 1   3		 13  16
			t.insert(3);//
			t.insert(10);//
			t.insert(9);//
			t.insert(15);//
			t.insert(13);//
			t.insert(16);//
			t.insert(5);//

			Iterator* tree_DFT_iterator = t.create_dft_iterator();
			Assert::AreEqual(tree_DFT_iterator->next(), 8);
			Assert::AreEqual(tree_DFT_iterator->next(), 4);
			Assert::AreEqual(tree_DFT_iterator->next(), 2);
			Assert::AreEqual(tree_DFT_iterator->next(), 1);
			Assert::AreEqual(tree_DFT_iterator->next(), 3);
			Assert::AreEqual(tree_DFT_iterator->next(), 5);
			Assert::AreEqual(tree_DFT_iterator->next(), 10);
			Assert::AreEqual(tree_DFT_iterator->next(), 9);
			Assert::AreEqual(tree_DFT_iterator->next(), 15);
			Assert::AreEqual(tree_DFT_iterator->next(), 13);
			Assert::AreEqual(tree_DFT_iterator->next(), 16);
		}

		TEST_METHOD(DFT_TEST2)
		{
			Tree t;

			t.insert(8);//			8
			t.insert(4);//		4		10
			t.insert(2);//	 2	   5  9    15
			t.insert(1);// 1   3		 13  16
			t.insert(3);//
			t.insert(10);//
			t.insert(9);//
			t.insert(15);//
			t.insert(13);//
			t.insert(16);//
			t.insert(5);//

			t.remove(10);
			Assert::IsTrue(!t.contains(10));
			Iterator* tree_DFT_iterator = t.create_dft_iterator();
			Assert::AreEqual(tree_DFT_iterator->next(), 8);
			Assert::AreEqual(tree_DFT_iterator->next(), 4);
			Assert::AreEqual(tree_DFT_iterator->next(), 2);
			Assert::AreEqual(tree_DFT_iterator->next(), 1);
			Assert::AreEqual(tree_DFT_iterator->next(), 3);
			Assert::AreEqual(tree_DFT_iterator->next(), 5);
			Assert::AreEqual(tree_DFT_iterator->next(), 13);
			Assert::AreEqual(tree_DFT_iterator->next(), 9);
			Assert::AreEqual(tree_DFT_iterator->next(), 15);
			Assert::AreEqual(tree_DFT_iterator->next(), 16);
		}

	};
}
