//	gtest_main.cpp
#include <iostream>
#include "gtest/gtest.h"

void foo()
{
	std::cerr << "bye bye foo" << std::endl;
	exit(1);
}

void bar()
{
	std::cerr << "bye bye bar" << std::endl;
	raise(SIGTERM);
}

//	Add the suffix "DeathTest" to the first argument of TEST()

TEST(HowToAssertDeathTest, KillMySelf)
{
	ASSERT_DEATH(foo(), "bye bye foo");
	ASSERT_EXIT(foo(), ::testing::ExitedWithCode(1), "bye bye foo");
	ASSERT_EXIT(bar(), ::testing::KilledBySignal(SIGTERM), "bye bye bar");
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
