#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD2(sum, int(int&, int));
};

TEST(ActionTest, SideEffect) {
	MockDOC mock;
	int var = 2;
	int& ref = var;

	EXPECT_CALL(mock, sum(_, _)).WillOnce(DoAll(SetArgReferee<0>(200), Return(100)));

	std::cout << "sum: " << mock.sum(ref, 1) << std::endl;
	std::cout << "ref: " << ref << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
