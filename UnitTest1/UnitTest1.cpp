#include "pch.h"
#include "CppUnitTest.h"
#include "..//2SAPlab2.7/main.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			int data = 5;
			Node* node = new Node(data);
			Assert::AreEqual(node->data, data);
			Assert::IsNull(node->next);
			delete node; 
		}
	};
}
