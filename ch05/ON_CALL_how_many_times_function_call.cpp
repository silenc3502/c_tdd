#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MockDOC() {
		ON_CALL(*this, boo(_)).WillByDefault(Return(1));
	}

	MOCK_METHOD1(foo, int(int));
	MOCK_METHOD1(boo, int(int));
};

TEST(ClauseTest, Generalize3) {
	MockDOC doc;

	EXPECT_CALL(doc, foo(1)).WillOnce(Return(1));

	if (doc.boo(1)) {
		std::cout << doc.foo(1) << std::endl;
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
