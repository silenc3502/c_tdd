#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD2(sum, int(int, int));
};

ACTION(foo) {
	StaticAssertTypeEq<int, arg0_type>;
	StaticAssertTypeEq<int, arg1_type>;

	return get<0>(args) - get<1>(args);
}

TEST(ActionTest, Others) {
	MockDOC mock;

	EXPECT_CALL(mock, sum(_, _)).WillOnce(foo());

	std::cout << "sum: " << mock.sum(2, 1) << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
