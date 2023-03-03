//	gtest_main1.cpp
#include <iostream>
#include "gtest/gtest.h"

TEST(AssertionTest, BasicTypes)
{
	EXPECT_EQ(1, 3-2);
	EXPECT_NE(2, 3-2);

	EXPECT_TRUE(1 == (3-2));
	EXPECT_FALSE(2 == (3-2));

	EXPECT_LT(1, 2);
	EXPECT_LE(2, 2);

	EXPECT_GT(2, 1);
	EXPECT_GE(2, 2);

	EXPECT_STREQ("ABC", "ABC");
	EXPECT_STRNE("ABC", "abc");

	EXPECT_STRCASEEQ("ABC", "abc");
	EXPECT_STRCASENE("ABC", "cba");

	EXPECT_FLOAT_EQ(3.0f, 3.0f);
	EXPECT_DOUBLE_EQ(3.0, 3.0);
}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
