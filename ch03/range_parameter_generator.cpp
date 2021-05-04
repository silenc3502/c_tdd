#include <iostream>
#include <stack>

#include "gtest/gtest.h"

using namespace std;
using namespace ::testing;

class VPTest : public TestWithParam<int> {};

INSTANTIATE_TEST_SUITE_P(VPTestData, VPTest, Range(1, 5));
INSTANTIATE_TEST_SUITE_P(VPTestData2, VPTest, Range(1, 7, 2));

TEST_P(VPTest, Range) {
	int param = GetParam();

	cout << "param: " << param << endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
