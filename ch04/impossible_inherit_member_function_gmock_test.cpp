#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using namespace ::testing;

#include "sut8.h"

class MockDOC {
public:
	MOCK_METHOD0(foo, string());
};

TEST(SutTest, UseMock) {
	DOC doc;
	SUT<DOC> sut(doc);

	MockDOC mock_doc;
	SUT<MockDOC> mock_sut(mock_doc);

	EXPECT_CALL(mock_doc, foo()).WillRepeatedly(Return("Mocked foo"));

	sut.foo();
	mock_sut.foo();
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
