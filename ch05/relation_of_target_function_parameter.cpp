#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD3(foo, void(int, int, int));
};

TEST(ClauseTest, With) {
	MockDOC mock_doc;

	EXPECT_CALL(mock_doc, foo(_, _, _)).With(Args<0, 2>(Gt()));

	mock_doc.foo(3, 2, 1);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
