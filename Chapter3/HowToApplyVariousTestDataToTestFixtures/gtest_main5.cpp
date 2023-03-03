//	gtest_main5.cpp - range generator
#include <iostream>
#include "gtest/gtest.h"

class VPTest : public ::testing::TestWithParam<int> {};

TEST_P(VPTest, Range)
{
	int param	= GetParam();
	std:: cout << "param: " << param << std::endl;
}

INSTANTIATE_TEST_SUITE_P(VPTestData, VPTest, ::testing::Range(1, 5));
INSTANTIATE_TEST_SUITE_P(VPTestData2, VPTest, ::testing::Range(10, 50, 2));	// With a step

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
