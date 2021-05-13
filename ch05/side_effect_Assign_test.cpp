#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD2(sum, int(int, int));
};

TEST(ActionTest, SideEffect) {
	MockDOC mock;
	int var = 0;

	EXPECT_CALL(mock, sum(_, _)).WillOnce(DoAll(Assign(&var, 200), Return(100)));

	std::cout << "sum: " << mock.sum(2, 1) << std::endl;
	std::cout << "var: " << var << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
