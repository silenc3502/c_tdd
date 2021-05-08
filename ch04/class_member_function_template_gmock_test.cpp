#include <iostream>
#include <string>
#include <typeinfo>
#include <type_traits>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using namespace ::testing;

#include "sut2.h"

class MockDOC {
public:
	MOCK_METHOD1(foo_tc1, string(int param));
	MOCK_METHOD1(foo_tc2, string(int param));

	template <typename T>
	string foo(T& param) {
		if(is_same<T, TestClass_1>::value) {
			return foo_tc1(1);
		} else if(is_same<T, TestClass_2>::value) {
			return foo_tc2(2);
		}
	}
};

TEST(SutTest, UseMock) {
	DOC doc;
	SUT<DOC> sut(doc);

	MockDOC mock_doc;
	SUT<MockDOC> mock_sut(mock_doc);

	EXPECT_CALL(mock_doc, foo_tc1(_)).WillOnce(Return("Mocked foo(TestClass_1)"));
	EXPECT_CALL(mock_doc, foo_tc2(_)).WillOnce(Return("Mocked foo(TestClass_2)"));

	sut.foo();
	mock_sut.foo();
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
