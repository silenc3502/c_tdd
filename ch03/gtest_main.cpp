#include <iostream>
#include "gtest/gtest.h"

TEST(AssertionTest, AssertFamily) {
	int *ptr = nullptr;
	ASSERT_TRUE(ptr != nullptr);

	std::cout << *ptr << std::endl;
}

TEST(AssertTest, ExpectFamily) {
	int *ptr = nullptr;
	EXPECT_TRUE(ptr != nullptr);

	std::cout << *ptr << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
