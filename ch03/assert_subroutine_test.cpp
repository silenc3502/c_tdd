#include <iostream>
#include "gtest/gtest.h"

void foo(int *ptr) {
	ASSERT_NE(ptr, nullptr);
}

TEST(HowToAssert, Subroutine) {
	int *ptr = nullptr;
	foo(ptr);

	if (HasFatalFailure()) {
		return;
	} else {
		*ptr = 3;
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
