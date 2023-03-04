//	test/gtest_main1.cpp

#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#if defined(MEMORY_LEAK_TEST) && defined(_MSC_VER)
	#include "vld.h"
#endif

#include "sut.h"

class MockDOC : public DOC
{
public:
	MOCK_METHOD0(foo, std::string());
};

TEST(SutTest, UseMock)
{
	//	Arrange
	DOC		doc;
	SUT		sut(doc);

	MockDOC	mock_doc;
	SUT		mock_sut(mock_doc);

	//	Expect
	EXPECT_CALL(mock_doc, foo()).WillRepeatedly(::testing::Return("I'm mocked foo (int)"));

	//	Act
	sut.foo();
	mock_sut.foo();
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
