//	gtest_main7.cpp - values in generator
#include <iostream>
#include "gtest/gtest.h"

class VPTest : public ::testing::TestWithParam<int*> {};

TEST_P(VPTest, ValuesIn)
{
	int* params	= GetParam();
	std:: cout << "params: " << params[0] << ", " << params[1] << std::endl;
}

static int d1[]	= {1, 2};
static int d2[] = {-1, -2};
static int d3[] = {3, 4};
static std::vector<int*> data {d1, d2, d3};
static int d4[] = {-3, -4};
static std::vector<int*> data2 {d1, d2, d3, d4};

INSTANTIATE_TEST_SUITE_P(VPTestData, VPTest, ::testing::ValuesIn(data));
INSTANTIATE_TEST_SUITE_P(VPTestData2, VPTest, ::testing::ValuesIn(data2.begin(), data2.end()));

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
