//	test/gtest_main1.cpp

#include <iostream>
#include <memory>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#if defined(MEMORY_LEAK_TEST) && defined(_MSC_VER)
	#include "vld.h"
#endif

#include "sut.h"

class MockMyDOC
{
public:
	static std::unique_ptr<MockMyDOC> mock_doc;
	MOCK_METHOD1(usleep, int(useconds_t));
};

std::unique_ptr<MockMyDOC>	MockMyDOC::mock_doc(nullptr);

int usleep(useconds_t useconds)
{
	std::cout << "I'm mocked usleep, I don't sleep anymore" << std::endl;

	return MockMyDOC::mock_doc->usleep(useconds);
}

TEST(SutTest, UseMock)
{
	//	Arrange
	SUT		mock_sut;

	MockMyDOC::mock_doc = std::unique_ptr<MockMyDOC>(new MockMyDOC());

	//	Expect
	EXPECT_CALL(*MockMyDOC::mock_doc, usleep(::testing::_)).WillRepeatedly(::testing::Return(0));

	//	Act
	mock_sut.foo(12000000);
	MockMyDOC::mock_doc	= nullptr;
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
