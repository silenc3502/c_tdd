#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD0(foo, void());
	MOCK_METHOD0(boo, void());
	MOCK_METHOD0(goo, void());
};

TEST(ClauseTest, InSequence) {
	MockDOC mock_doc;

	Sequence s1, s2;

	EXPECT_CALL(mock_doc, foo()).InSequence(s1, s2);
	EXPECT_CALL(mock_doc, boo()).InSequence(s1);
	EXPECT_CALL(mock_doc, goo()).InSequence(s2);

	mock_doc.foo();
	mock_doc.boo();
	mock_doc.goo();
}

TEST(ClauseTest2, After) {
	MockDOC mock_doc;

	Expectation efoo = EXPECT_CALL(mock_doc, foo());
	Expectation eboo = EXPECT_CALL(mock_doc, boo());

	EXPECT_CALL(mock_doc, goo()).After(efoo, eboo);

	mock_doc.foo();
	mock_doc.boo();
	mock_doc.goo();
}

TEST(ClauseTest3, After) {
	MockDOC mock_doc;

	ExpectationSet es;

	es += EXPECT_CALL(mock_doc, foo());
	es += EXPECT_CALL(mock_doc, boo());

	EXPECT_CALL(mock_doc, goo()).After(es);

	mock_doc.foo();
	mock_doc.boo();
	mock_doc.goo();
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
