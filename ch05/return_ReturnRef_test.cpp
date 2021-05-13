#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD2(sum, int&(int, int));
};

TEST(ActionTest, Return) {
	MockDOC mock;
	int var = 100;
	int& ref = var;

	EXPECT_CALL(mock, sum(_, _)).WillOnce(ReturnRef(ref));

	var = 200;
	std::cout << "sum: " << mock.sum(2, 1) << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
