#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD2(sum, int(int, int));
};

int foo(int a, int b) { return a - b; } 
int boo() { return 100; }

TEST(ActionTest, Others) {
	MockDOC mock;

	{
		InSequence s;

		EXPECT_CALL(mock, sum(_, _)).WillOnce(Invoke(foo));
		EXPECT_CALL(mock, sum(_, _)).WillOnce(WithArgs<0, 0>(Invoke(foo)));
		EXPECT_CALL(mock, sum(_, _)).WillOnce(WithoutArgs(Invoke(boo)));
		EXPECT_CALL(mock, sum(_, _))
			.WillOnce(DoAll(WithArgs<0, 1>(Invoke(foo)), Return(200)));
	}

	std::cout << "sum: " << mock.sum(2, 1) << std::endl;
	std::cout << "sum: " << mock.sum(2, 1) << std::endl;
	std::cout << "sum: " << mock.sum(2, 1) << std::endl;
	std::cout << "sum: " << mock.sum(2, 1) << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
