#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using namespace ::testing;

#include "sut4.h"

class MockMyDOC {
public:
	MOCK_METHOD1(foo_int, string(int param));
	MOCK_METHOD1(foo_double, string(double param));

	template <typename T>
	string Foo(T param) { return "mocked foo(other types)"; }
};

template<>
string MockMyDOC::Foo<int>(int param) { return foo_int(param); }

template<>
string MockMyDOC::Foo<double>(double param) { return foo_double(param); }

TEST(SutTest, UseMock) {
	MyDOC obj;
	SUT<MyDOC> sut(obj);

	MockMyDOC mock_obj;
	SUT<MockMyDOC> mock_sut(mock_obj);

	EXPECT_CALL(mock_obj, foo_int(_)).WillOnce(Return("Mocked foo(int)"));
	EXPECT_CALL(mock_obj, foo_double(_)).WillOnce(Return("Mocked foo(double)"));

	sut.foo();
	mock_sut.foo();
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
