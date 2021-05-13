#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MockDOC() {
		EXPECT_CALL(*this, foo(_))
			.Times(AnyNumber())
			.WillRepeatedly(Return(0));
	}

	MOCK_METHOD1(foo, int(int));
};

TEST(ClauseTest, Generalize1) {
	MockDOC doc;

	EXPECT_CALL(doc, foo(1)).WillOnce(Return(1));

	std::cout << doc.foo(1) << std::endl;
	std::cout << doc.foo(100) << std::endl;
}

TEST(ClauseTest, Generalize2) {
	MockDOC doc;

	EXPECT_CALL(doc, foo(2)).WillOnce(Return(2));

	std::cout << doc.foo(2) << std::endl;
	std::cout << doc.foo(200) << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
