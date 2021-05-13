#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD0(foo, void());
	MOCK_METHOD0(boo, void());
};

TEST(ClauseTest, Times) {
	MockDOC mock_doc;

	EXPECT_CALL(mock_doc, foo()).Times(3);
	EXPECT_CALL(mock_doc, boo()).Times(0);

	mock_doc.foo();
	mock_doc.foo();
	mock_doc.foo();
}

TEST(ClauseTest2, Times) {
	MockDOC mock_doc;

	EXPECT_CALL(mock_doc, foo()).Times(AtLeast(3));
	EXPECT_CALL(mock_doc, boo()).Times(AnyNumber());

	mock_doc.foo();
	mock_doc.foo();
	mock_doc.foo();
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
