//	gtest_main8.cpp - combine generator
#include <iostream>
#include "gtest/gtest.h"

class VPTest : public ::testing::TestWithParam<std::tuple<int, int>> {};

TEST_P(VPTest, Combine)
{
	std::tuple<int, int> param	= GetParam();
	std:: cout << "param: " << std::get<0>(param) << ", " << std::get<1>(param) << std::endl;
}

static std::tuple<int, int> d1 = {1, 2};
static std::tuple<int, int> d2 = {-1, -2};
static std::tuple<int, int> d3 = {3, 4};
static std::vector<std::tuple<int, int>> data {d1, d2, d3};
static std::tuple<int, int> d4 = {-3, -4};
std::vector<std::tuple<int, int>> data2 {d1, d2, d3, d4};

INSTANTIATE_TEST_SUITE_P(VPTestData, VPTest, ::testing::Combine(::testing::Values(10,11), ::testing::Values(12,13)));
INSTANTIATE_TEST_SUITE_P(VPTestData2, VPTest, ::testing::Values(d1, d2, d3));
INSTANTIATE_TEST_SUITE_P(VPTestData3, VPTest, ::testing::ValuesIn(data));
INSTANTIATE_TEST_SUITE_P(VPTestData4, VPTest, ::testing::ValuesIn(data2.begin(), data2.end()));

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
