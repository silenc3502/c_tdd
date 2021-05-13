#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

class MockDOC {
public:
	MOCK_METHOD2(sum, int(int, int));
};

ACTION_TEMPLATE(foo, HAS_1_TEMPLATE_PARAMS(typename, T), AND_2_VALUE_PARAMS(p1, p2)) {
	if (is_same<T, char>::value) {
		if (isdigit(p1) && isdigit(p2)) {
			return (p1 - '0') + (p2 - '0') + get<0>(args) + get<1>(args);
		}
	} else if (is_same<T, int>::value) {
		return p1 + p2 + get<0>(args) + get<1>(args);
	}

	return -1;
}

TEST(ActionTest, Others) {
	MockDOC mock;

	EXPECT_CALL(mock, sum(_, _))
		.WillOnce(foo<int>(1, 2))
		.WillOnce(foo<char>('1', '2'));

	cout << "sum: " << mock.sum(3, 4) << endl;
	cout << "sum: " << mock.sum(3, 4) << endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
