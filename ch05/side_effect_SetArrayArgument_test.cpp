#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD2(sum, int(int[], int));
};

TEST(ActionTest, SideEffect) {
	MockDOC mock;

	vector<int> vec1 { 10, 20, 30 };
	int arr[] = { 0, 0, 0 };

	EXPECT_CALL(mock, sum(_, _))
		.WillOnce(DoAll(SetArrayArgument<0>(vec1.begin(), vec1.end()), Return(200)));

	cout << "sum: " << mock.sum(arr, 1) << std::endl;

	cout << "arr[0]: " << arr[0] << endl;
	cout << "arr[1]: " << arr[1] << endl;
	cout << "arr[2]: " << arr[2] << endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
