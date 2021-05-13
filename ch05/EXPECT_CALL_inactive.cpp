#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD0(foo, int());
};

TEST(ClauseTest, RetiresOnSaturation) {
	MockDOC mock_doc;

	for (int i = 10; i > 0; --i) {
		EXPECT_CALL(mock_doc, foo())
			.WillOnce(Return(i))
			.RetiresOnSaturation();
	}

	for (int i = 10; i > 0; --i) {
		std::cout << mock_doc.foo() << std::endl;
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
