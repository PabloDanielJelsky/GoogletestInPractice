//	gtest_main3.cpp
#include <iostream>
#include <stack>
#include "gtest/gtest.h"

class StackTestP : public ::testing::TestWithParam<int*>
{
protected:
	std::stack<int>	s;

	void SetUp() override
	{
		int*	params	= GetParam();

		s.push(params[0]);
		s.push(params[1]);
		s.push(params[2]);

		std::cout << "params: " << params[0] << ", " << params[1] << ", " << params[2];
	}

	void TearDown() override {}
};

TEST_P(StackTestP, Size)
{
	int cnt = s.size();
	for (int i = 0; i < cnt; i++)
	{
		s.push(i);
	}

	ASSERT_EQ(cnt*2, s.size());
}

TEST_P(StackTestP, Empty)
{
	int cnt = s.size();
	for (int i = 0; i < cnt; i++)
	{
		s.pop();
	}

	ASSERT_TRUE(s.empty());
}

static int	d1[] = {1, 2, 3};
static int 	d2[] = {-1, -2, -3};
static std::vector<int*> data = {d1, d2};
static int	d3[] = {11, 12, 13};
static int 	d4[] = {-11, -12, -13};
static std::vector<int*> data2 = {d3, d4};

INSTANTIATE_TEST_SUITE_P(StackTestData, StackTestP, ::testing::ValuesIn(data));
INSTANTIATE_TEST_SUITE_P(StackTestData2, StackTestP, ::testing::ValuesIn(data2));	//	added line

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
