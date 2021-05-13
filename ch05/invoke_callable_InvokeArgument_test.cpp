#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD1(sum, int(int (*)(int, int)));
};

int foo(int a, int b) { return a - b; }

TEST(ActionTest, Invoke) {
	MockDOC mock;

	EXPECT_CALL(mock, sum(_)).WillOnce(InvokeArgument<0>(2, 1));

	std::cout << "sum: " << mock.sum(foo) << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
