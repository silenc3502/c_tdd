#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class Base {
public:
	virtual ~Base() {}
};

class Derived : public Base {
public:
	const int x = 2;
};

MATCHER(M0, "") {
	return (arg.x > 1) && (arg.x <= 2);
}

MATCHER_P(M1, param_1, "") {
	return (arg.x > 1) && (arg.x <= param_1);
}

MATCHER_P2(M2, param_1, param_2, "") {
	return (arg.x > param_1) && (arg.x <= param_2);
}

MATCHER_P2(M3, param_1, param_2, "") {
	return (arg->x > param_1) && (arg->x <= param_2);
}

TEST(MatcherTest, Others) {
	Derived obj1;

	EXPECT_THAT(obj1, M0());
	EXPECT_THAT(obj1, M1(2));
	EXPECT_THAT(obj1, M2(1, 2));

	Base *obj2 = new Derived();
	EXPECT_THAT(obj2, WhenDynamicCastTo<const Derived *>(M3(1, 2)));

	delete(obj2);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
