//	example/test/gtest_ex4.cpp

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

void foo()
{
	char* ptr	= (char*)malloc(1);
	*ptr		= 0;
	free(ptr);
}

void bar()
{
	char* ptr	= (char*)calloc(1, sizeof(char));
	*ptr		= 0;
	free(ptr);
}

void baz()
{
	char* ptr	= new char();
	*ptr		= 0;
	delete ptr;
}

TEST(LeakTest, MallocCallocNew)
{
	foo();
	bar();
	baz();
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
