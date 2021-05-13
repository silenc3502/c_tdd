#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD3(sum, int(int, int, int (*)(int, int)));
};

int foo(int a, int b) { return a - b; }

TEST(ActionTest, Invoke) {
	MockDOC mock;
	int var1 = 2;
	int var2 = 2;

	EXPECT_CALL(mock, sum(_, _, _)).WillOnce(InvokeArgument<2>(var1, var2));

	var2 = 1;
	std::cout << "sum: " << mock.sum(0, 0, foo) << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
