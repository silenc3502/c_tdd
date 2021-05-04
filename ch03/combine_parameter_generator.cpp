#include <iostream>

#include "gtest/gtest.h"

using namespace std;
using namespace ::testing;

class VPTest : public TestWithParam<tuple<int, int>> {};

INSTANTIATE_TEST_SUITE_P(VPTestData, VPTest, Combine(Values(1, 2), Values(-1, -2)));

TEST_P(VPTest, Bool) {
	tuple<int, int> param = GetParam();

	cout << "param: " << get<0>(param) << ", " << get<1>(param) << endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
