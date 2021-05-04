#include <iostream>
#include <stack>

#include "gtest/gtest.h"

using namespace std;
using namespace ::testing;

class VPTest : public TestWithParam<int *> {};

static int d1[] = {1, 2};
static int d2[] = {-1, -2};

INSTANTIATE_TEST_SUITE_P(VPTestData, VPTest, Values(d1, d2));

TEST_P(VPTest, Values) {
	int *params = GetParam();

	cout << "params: " << params[0] << ", " << params[1] << endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
