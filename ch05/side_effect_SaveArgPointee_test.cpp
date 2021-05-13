#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD2(sum, int(int *, int));
};

TEST(ActionTest, SideEffect) {
	MockDOC mock;
	int *ptr1 = new int(2);
	int *ptr2 = new int(0);

	EXPECT_CALL(mock, sum(_, _)).WillOnce(DoAll(SaveArgPointee<0>(ptr2), Return(100)));

	std::cout << "sum: " << mock.sum(ptr1, 1) << std::endl;
	std::cout << "*ptr2: " << *ptr2 << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
