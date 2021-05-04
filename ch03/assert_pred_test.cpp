#include <iostream>
#include "gtest/gtest.h"

class MyClass {
public:
	int data;
	MyClass(int param) : data(param) {}
};

bool foo(MyClass param1, MyClass param2) {
	return param1.data == param2.data;
}

TEST(AssertionTest, MyClass) {
	MyClass obj1(2);
	MyClass obj2(2);

	ASSERT_PRED2(foo, obj1, obj2);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
