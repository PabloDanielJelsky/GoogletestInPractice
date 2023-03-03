//	gtest_main6.cpp - values generator
#include <iostream>
#include "gtest/gtest.h"

class VPTest : public ::testing::TestWithParam<int*> {};

TEST_P(VPTest, Values)
{
	int* params	= GetParam();
	std:: cout << "params: " << params[0] << ", " << params[1] << std::endl;
}

static int d1[]	= {1, 2};
static int d2[] = {-1, -2};
static int d3[] = {3, 4};

INSTANTIATE_TEST_SUITE_P(VPTestData, VPTest, ::testing::Values(d1, d2, d3));

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
