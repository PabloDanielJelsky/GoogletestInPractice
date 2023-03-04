//	test/gtest_main1.cpp

#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#if defined(MEMORY_LEAK_TEST) && defined(_MSC_VER)
	#include "vld.h"
#endif

#include "sut.h"

class MockMyDOC : public MyDOC
{
public:
	MOCK_METHOD1(Foo, std::string(int));
};

TEST(SutTest, UseMock)
{
	//	Arrange
	MyDOC		doc;
	SUT			sut(doc);

	MockMyDOC	mock_doc;
	SUT			mock_sut(mock_doc);

	//	Expect
	EXPECT_CALL(mock_doc, Foo(::testing::_)).WillRepeatedly(::testing::Return("I'm mocked foo : 100"));

	//	Act
	sut.foo();
	mock_sut.foo();
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
