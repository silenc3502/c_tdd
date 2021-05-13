#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD0(foo, int());
};

TEST(ClauseTest, RetiresOnSaturation) {
	MockDOC mock_doc;

	{
		InSequence s;

		for (int i = 10; i > 0; --i) {
			EXPECT_CALL(mock_doc, foo()).WillOnce(Return(i));
		}
	}

	for (int i = 1; i <= 10; ++i) {
		std::cout << mock_doc.foo() << std::endl;
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
