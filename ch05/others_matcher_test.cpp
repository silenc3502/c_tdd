#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

int foo(int arg) { return arg + 1; }

TEST(MatcherTest, Others) {
	int var = 0;

	EXPECT_THAT(var, AllOf(Ge(0), Lt(2)));
	EXPECT_THAT(var, AnyOf(Ge(1), Lt(2)));
	EXPECT_THAT(var, Not(Gt(1)));
	EXPECT_THAT(var, ResultOf(foo, Lt(2)));

	for (int i = 0; i < 100; i++) {
		EXPECT_THAT(i, _);
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
