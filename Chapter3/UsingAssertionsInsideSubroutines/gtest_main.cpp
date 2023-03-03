//	gtest_main.cpp
#include <iostream>
#include "gtest/gtest.h"

void foo(int* ptr)
{
	ASSERT_NE(ptr, nullptr);	// success if ptr is not equal to nullptr
}

TEST(HowToAssert, Subroutine)
{
	int*	ptr	= nullptr;
	foo(ptr);

	if (HasFatalFailure())	// or HasFailure()
	{
		return;
	}
	else
	{
		*ptr	= 3;		// this line can cause a segmentation fault
	}
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
