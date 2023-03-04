//	test/gtest_main.cpp

#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#if defined(MEMORY_LEAK_TEST) && defined(_MSC_VER)
	#include "vld.h"
#endif

#include "sut.h"

template<typename T>

class MockDOC : public DOC<T>
{
public:
	MOCK_METHOD1(foo, std::string(T param));
};

TEST(SutTest, UseMock)
{
	//	Arrange
	DOC<int>		doc;
	SUT				sut(doc);

	MockDOC<int>	mock_doc;
	SUT				mock_sut(mock_doc);

	//	Expect
	EXPECT_CALL(mock_doc, foo(::testing::_)).WillOnce(::testing::Return("I'm mocked foo"));

	//	Act
	sut.foo();
	mock_sut.foo();
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
