#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD3(sum, int(int, int, int));
};

int foo(int a, int b) { return a - b; }

TEST(ActionTest, Invoke) {
	MockDOC mock;

	EXPECT_CALL(mock, sum(_, _, _)).WillOnce(WithArgs<2, 1>(Invoke(foo)));

	std::cout << "sum: " << mock.sum(1, 2, 3) << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
