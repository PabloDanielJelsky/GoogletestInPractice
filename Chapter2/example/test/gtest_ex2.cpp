//	example/test/gtest_ex2.cpp

#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#if defined(MEMORY_LEAK_TEST) && defined(_MSC_VER)
	#include "vld.h"
#endif

#include "doc.h"
#include "sut.h"

using namespace std;
using namespace ::testing;

int foo()
{
	int	*array	= new int[100];
	delete[] array;
	return array[5];
}

TEST(ASanTest, HeapUseAfterFree)
{
	foo();
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
