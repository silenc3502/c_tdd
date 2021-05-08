#include <iostream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using namespace ::testing;

#include "sut5.h"

class MockMyDOC : public MyDOC {
public:
	MOCK_METHOD1(Foo, string(int));
};

TEST(SutTest, UseMock) {
	MyDOC doc;
	SUT sut(doc);

	MockMyDOC mock_doc;
	SUT mock_sut(mock_doc);

	EXPECT_CALL(mock_doc, Foo(_)).WillRepeatedly(Return("Mocked foo: 100"));

	sut.foo();
	mock_sut.foo();
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
