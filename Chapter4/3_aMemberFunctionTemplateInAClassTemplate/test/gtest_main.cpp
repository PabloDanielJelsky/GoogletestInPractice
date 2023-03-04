//	test/gtest_main1.cpp

#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#if defined(MEMORY_LEAK_TEST) && defined(_MSC_VER)
	#include "vld.h"
#endif

#include "sut.h"

template<typename T>
class MockDOC
{
public:
	MOCK_METHOD2(foo_ii, std::string(int param_1, int param_2));
	MOCK_METHOD2(foo_id, std::string(int param_1, double param_2));

	template<typename U>
	std::string foo(T param_1, U param_2) { return "I'm mocked foo (other types)"; }

	std::string foo(int param_1, int param_2) { return foo_ii(param_1, param_2); }
	std::string foo(int param_1, double param_2) { return foo_id(param_1, param_2); }
};

TEST(SutTest, UseMock)
{
	//	Arrange
	DOC<int>			doc;
	SUT<DOC<int>>		sut(doc);

	MockDOC<int>		mock_doc;
	SUT<MockDOC<int>>	mock_sut(mock_doc);

	//	Expect
	EXPECT_CALL(mock_doc, foo_ii(::testing::_, ::testing::_)).WillOnce(::testing::Return("I'm mocked foo (int, int)"));
	EXPECT_CALL(mock_doc, foo_id(::testing::_, ::testing::_)).WillOnce(::testing::Return("I'm mocked foo (int, double)"));

	//	Act
	sut.foo();
	mock_sut.foo();
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
