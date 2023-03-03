//	gtest_main4.cpp - boolean generator
#include <iostream>
#include "gtest/gtest.h"

class VPTest : public ::testing::TestWithParam<bool> {};

TEST_P(VPTest, Bool)
{
	bool param	= GetParam();
	std:: cout << "param: " << std::boolalpha << param << std::endl;
}

INSTANTIATE_TEST_SUITE_P(VPTestData, VPTest, ::testing::Bool());

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
