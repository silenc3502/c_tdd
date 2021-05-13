#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

Matcher<int> m1() { return AllOf(Gt(1), Le(2)); }

TEST(MatcherTest, Others) {
	Matcher<int> m2 = AllOf(Gt(1), Le(2));
	Matcher<int> m3 = AnyOf(Gt(1), Le(2));
	Matcher<int> m4 = Not(Gt(1));

	EXPECT_THAT(2, m1());
	EXPECT_THAT(2, m2);
	EXPECT_THAT(0, m3);
	EXPECT_THAT(0, m4);

	EXPECT_TRUE(m1().Matches(2));
	EXPECT_TRUE(m2.Matches(2));
	EXPECT_TRUE(m3.Matches(0));
	EXPECT_TRUE(m4.Matches(0));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
