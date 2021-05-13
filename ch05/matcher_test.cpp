#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class MockDOC {
public:
	MOCK_METHOD2(foo, void(int, int));
};

TEST(MatcherTest, First) {
	MockDOC mock_doc;

	EXPECT_CALL(mock_doc, foo(Eq(0), Gt(0)));

	mock_doc.foo(0, 0);
}

TEST(MatcherTest2, Second) {
	EXPECT_THAT(1, Eq(0));
	ASSERT_THAT(0, Eq(0));
}

TEST(MatcherTest3, Second) {
	ASSERT_THAT(1, Eq(1));
	ASSERT_THAT(1, Ne(2));
	ASSERT_THAT(1, TypedEq<int>(1));
	ASSERT_THAT(1 == 3 - 2, IsTrue());
	ASSERT_THAT(2 == 3 - 2, IsFalse());

	ASSERT_THAT(1, Lt(2));
	ASSERT_THAT(2, Le(2));

	ASSERT_THAT(2, Gt(1));
	ASSERT_THAT(1, Ge(1));

	ASSERT_THAT(nullptr, IsNull());
	ASSERT_THAT(new int(1), NotNull());

	ASSERT_THAT(1.0f, FloatEq(1));
	ASSERT_THAT(1.0, DoubleEq(1));

	ASSERT_THAT("Foo", StrEq("Foo"));
	ASSERT_THAT("Goo", StrNe("Foo"));
	ASSERT_THAT("Fooooo", HasSubstr("Foo"));

	int var = 1;
	int& ref = var;
	int *ptr = new int(1);

	ASSERT_THAT(ref, Ref(var));
	ASSERT_THAT(ptr, Pointee(Eq(1)));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
