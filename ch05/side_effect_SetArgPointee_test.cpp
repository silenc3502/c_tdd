#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD2(sum, int(int *, int));
};

TEST(ActionTest, SideEffect) {
	MockDOC mock;
	int *ptr = new int(2);

	EXPECT_CALL(mock, sum(_, _)).WillOnce(DoAll(SetArgPointee<0>(200), Return(100)));

	std::cout << "sum: " << mock.sum(ptr, 1) << std::endl;
	std::cout << "*ptr: " << *ptr << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
