#include <iostream>
#include <stack>

#include "gtest/gtest.h"

using namespace std;
using namespace ::testing;

class VPTest : public TestWithParam<bool> {};

INSTANTIATE_TEST_SUITE_P(VPTestData, VPTest, Bool());

TEST_P(VPTest, Bool) {
	bool param = GetParam();
	cout << "param: " << boolalpha << param << endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
