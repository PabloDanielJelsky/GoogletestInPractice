//	test/gtest_main.cpp

#include <iostream>
#include <string>
#include <typeinfo>
#include <type_traits>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#if defined(MEMORY_LEAK_TEST) && defined(_MSC_VER)
	#include "vld.h"
#endif

#include "sut.h"

class MockDOC
{
public:
	MOCK_METHOD1(foo_tc1, std::string(int param));
	MOCK_METHOD1(foo_tc2, std::string(int param));

	template<typename T>
	std::string foo(T& param)
	{
		if (std::is_same<T, TestClass_1>::value)
		{
			return foo_tc1(1);
		}
		else if (std::is_same<T, TestClass_2>::value)
		{
			return foo_tc2(2);
		}
	}
};

TEST(SutTest, UseMock)
{
	//	Arrange
	DOC				doc;
	SUT<DOC>		sut(doc);

	MockDOC			mock_doc;
	SUT<MockDOC>	mock_sut(mock_doc);

	//	Expect
	EXPECT_CALL(mock_doc, foo_tc1(::testing::_)).WillOnce(::testing::Return("I'm mocked foo (TestClass_1)"));
	EXPECT_CALL(mock_doc, foo_tc2(::testing::_)).WillOnce(::testing::Return("I'm mocked foo (TestClass_2)"));

	//	Act
	sut.foo();
	mock_sut.foo();
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
