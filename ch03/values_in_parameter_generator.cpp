#include <iostream>
#include <stack>

#include "gtest/gtest.h"

using namespace std;
using namespace ::testing;

class VPTest : public TestWithParam<int *> {};

static int d1[] = {1, 2};
static int d2[] = {-1, -2};
static vector<int *> data = {d1, d2};

INSTANTIATE_TEST_SUITE_P(VPTestData, VPTest, ValuesIn(data));
INSTANTIATE_TEST_SUITE_P(VPTestData2, VPTest, ValuesIn(data.begin(), data.end()));

TEST_P(VPTest, ValuesIn) {
	int *params = GetParam();

	cout << "params: " << params[0] << ", " << params[1] << endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
