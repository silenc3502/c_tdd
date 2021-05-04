#include <iostream>
#include "gtest/gtest.h"

TEST(AssertionTest, BasicTypes) {
	ASSERT_EQ(1, 3-2);
	ASSERT_NE(2, 3-2);

	ASSERT_TRUE(1 == (3-2));
	ASSERT_FALSE(2 == (3-2));

	ASSERT_LT(1, 2);
	ASSERT_LE(2, 2);

	ASSERT_GT(2, 1);
	ASSERT_GE(2, 2);

	ASSERT_STREQ("ABC", "ABC");
	ASSERT_STRNE("ABC", "abc");

	ASSERT_STRCASEEQ("ABC", "abc");
	ASSERT_STRCASENE("ABC", "cba");

	ASSERT_FLOAT_EQ(3.0f, 3.0f);
	ASSERT_DOUBLE_EQ(3.0, 3.0);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
