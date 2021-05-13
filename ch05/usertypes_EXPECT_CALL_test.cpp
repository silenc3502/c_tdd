#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MyClass {
public:
	int x;
	int getX() const { return x; }
};

class MockClass {
public:
	MOCK_METHOD1(foo, void(MyClass));
	MOCK_METHOD2(goo, void(MyClass, MyClass));
};

MATCHER_P(EqMyClass, param, "") { return arg.x == param.x; }

TEST (MatcherTest, UserTypes) {
	MyClass obj1 { 1 };
	MyClass obj2 { 1 };

	MockClass mock;

	EXPECT_CALL(mock, foo(EqMyClass(obj1)));
	EXPECT_CALL(mock, goo(EqMyClass(obj1), EqMyClass(obj1)));

	mock.foo(obj2);
	mock.goo(obj2, obj2);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
