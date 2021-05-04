#include <iostream>
#include "gtest/gtest.h"

class MyClass {
public:
	int data;
	MyClass(int param) : data(param) {}
	friend bool operator==(MyClass lhs, MyClass rhs);
};

bool operator==(MyClass lhs, MyClass rhs) {
	return lhs.data == rhs.data;
}

TEST(AssertionTest, MyClass) {
	MyClass obj1(2);
	MyClass obj2(2);

	ASSERT_EQ(obj1, obj2);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
