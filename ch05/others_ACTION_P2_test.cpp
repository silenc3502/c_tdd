#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD2(sum, int(int, int));
};

ACTION_P2(foo, param_1, param_2) { return param_1 - param_2 - arg0 - arg1; }

TEST(ActionTest, Others) {
	MockDOC mock;

	EXPECT_CALL(mock, sum(_, _)).WillOnce(foo(200, 100));

	std::cout << "sum: " << mock.sum(2, 1) << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
