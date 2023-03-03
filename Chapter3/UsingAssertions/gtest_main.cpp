//	gtest_main.cpp
#include <iostream>
#include "gtest/gtest.h"

TEST(AssertionTest, AssertFamily)
{
	int*	ptr	= nullptr;
	ASSERT_TRUE(nullptr != ptr);
	std::cout << *ptr << std::endl;
}

TEST(AssertionTest, ExpectFamily)
{
	int*	ptr	= nullptr;
	EXPECT_TRUE(nullptr != ptr);
	std::cout << *ptr << std::endl;
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
