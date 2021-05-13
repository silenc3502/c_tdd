#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MyClass {
public:
	int x;
	int getX() const { return x; }
};

bool CheckMyClass(MyClass arg) { return arg.x == 1 ? true : false; }
bool operator==(const MyClass& a1, const MyClass& a2) { return a1.x == a2.x; }
MATCHER_P(EqMyClass, param, "") { return arg.x == param.x; }

TEST (MatcherTest, UserTypes) {
	MyClass obj1 { 1 };
	MyClass obj2 { 1 };

	ASSERT_THAT(obj1, Truly(CheckMyClass));
	ASSERT_THAT(obj1, Eq(obj2));
	ASSERT_THAT(obj1, Field(&MyClass::x, Eq(obj2.x)));
	ASSERT_THAT(obj1, Property(&MyClass::getX, Eq(obj2.getX())));
	ASSERT_THAT(obj1, EqMyClass(obj2));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
