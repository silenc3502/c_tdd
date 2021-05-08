#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using namespace ::testing;

#include "sut3.h"

template <typename T>
class MockDOC {
public:
	MOCK_METHOD2(foo_ii, string(int param_1, int param_2));
	MOCK_METHOD2(foo_id, string(int param_1, double param_2));

	template <typename U>
	string foo(T param_1, U param_2) { return "foo(other types)"; }

	string foo(int param_1, int param_2) { return foo_ii(param_1, param_2); }
	string foo(int param_1, double param_2) { return foo_id(param_1, param_2); }
};

TEST(SutTest, UseMock) {
	DOC<int> doc;
	SUT<DOC<int>> sut(doc);

	MockDOC<int> mock_doc;
	SUT<MockDOC<int>> mock_sut(mock_doc);

	EXPECT_CALL(mock_doc, foo_ii(_, _)).WillOnce(Return("Mocked foo(int, int)"));
	EXPECT_CALL(mock_doc, foo_id(_, _)).WillOnce(Return("Mocked foo(int, double)"));

	sut.foo();
	mock_sut.foo();
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
