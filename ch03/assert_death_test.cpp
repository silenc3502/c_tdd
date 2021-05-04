#include <iostream>
#include "gtest/gtest.h"

void foo() {
	std::cerr << "self kill" << std::endl;
	exit(1);
}

void bar() {
	std::cerr << "self kill" << std::endl;
	raise(SIGTERM);
}

TEST(HowToAssertDeathTest, Death) {
	ASSERT_DEATH(foo(), "self kill");
	ASSERT_EXIT(foo(), ::testing::ExitedWithCode(1), "self kill");
	ASSERT_EXIT(bar(), ::testing::KilledBySignal(SIGTERM), "self kill");
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
