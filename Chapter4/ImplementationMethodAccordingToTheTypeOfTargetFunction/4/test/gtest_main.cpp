//	test/gtest_main1.cpp

#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#if defined(MEMORY_LEAK_TEST) && defined(_MSC_VER)
	#include "vld.h"
#endif

#include "sut.h"

class MockMyDOC
{
public:
	MOCK_METHOD1(foo_int, std::string(int param));
	MOCK_METHOD1(foo_double, std::string(double param));

	template<typename T>
	std::string Foo(T param) { return "I'm mocked foo (other types)"; }
};

template<>
std::string MockMyDOC::Foo<int>(int param) { return foo_int(param); }

template<>
std::string MockMyDOC::Foo<double>(double param) { return foo_double(param); }

TEST(SutTest, UseMock)
{
	//	Arrange
	MyDOC			obj;
	SUT<MyDOC>		sut(obj);

	MockMyDOC		mock_obj;
	SUT<MockMyDOC>	mock_sut(mock_obj);

	//	Expect
	EXPECT_CALL(mock_obj, foo_int(::testing::_)).WillOnce(::testing::Return("I'm mocked foo (int)"));
	EXPECT_CALL(mock_obj, foo_double(::testing::_)).WillOnce(::testing::Return("I'm mocked foo (double)"));

	//	Act
	sut.foo();
	mock_sut.foo();
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
