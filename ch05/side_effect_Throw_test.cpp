#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

class MockDOC {
public:
	MOCK_METHOD2(sum, int(int, int));
};

struct MyException : public exception {
	const char * what() const throw () {
		return "200";
	}
};

TEST(ActionTest, SideEffect) {
	MockDOC mock;

	EXPECT_CALL(mock, sum(_, _)).WillOnce(DoAll(Throw(MyException()), Return(100)));

	try {
		cout << "sum: " << mock.sum(2, 1) << endl;
	} catch (MyException& e) {
		cout << e.what() << endl;
	} catch (exception& e) {
		cout << e.what() << endl;
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
