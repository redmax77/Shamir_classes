#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Shamir_classes/field.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//using Shamir_classes;
namespace UnitTest_field
{		
	TEST_CLASS(UnitTest_field)
	{
	public:
		
		TEST_METHOD(Put_element_12_in_field_7)
		{
			field f1(7);
			Assert::AreEqual(5, f1.mod(12), 0.001, L"Basic test failed", LINE_INFO());
		}
		TEST_METHOD(get_symmetric_to_5_in_field_7)
		{
			field f2(7);
			Assert::AreEqual(2, f2.get_symmetric(5), 0.001, L"Basic test failed", LINE_INFO());
		}
		TEST_METHOD(get_inverse_to_2_in_field_5)
		{
			field f3(5);
			Assert::AreEqual(3, f3.get_inverse(2), 0.01, L"Basic test failed");
		}
	};
}