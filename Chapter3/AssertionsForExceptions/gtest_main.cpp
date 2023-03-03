//	gtest_main.cpp
#include <iostream>
#include "gtest/gtest.h"

int foo(int param1, int param2)
{
	if (0 == param2)
	{
		throw std::runtime_error("Division by zero!");
	}

	return param1 / param2;
}

TEST(HowToAssert, Exception)
{
	ASSERT_THROW(foo(3,0), std::runtime_error);
	ASSERT_ANY_THROW(foo(3,0));
	ASSERT_NO_THROW(foo(3,1));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
