#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD0(foo, int());
	MOCK_METHOD0(boo, int());
};

TEST(ClauseTest, WillFamily) {
	MockDOC mock_doc;

	EXPECT_CALL(mock_doc, foo())
		.WillOnce(Return(100));

	EXPECT_CALL(mock_doc, boo())
		.WillOnce(Return(100))
		.WillRepeatedly(Return(200));

	std::cout << mock_doc.foo() << std::endl;
	std::cout << mock_doc.boo() << std::endl;
	std::cout << mock_doc.boo() << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
