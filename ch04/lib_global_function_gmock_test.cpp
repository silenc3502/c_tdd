#include <iostream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using namespace ::testing;

#include "sut6.h"

class MockMyDOC {
public:
	static MockMyDOC *mock_doc;
	MOCK_METHOD1(usleep, int(useconds_t));
};

MockMyDOC *MockMyDOC::mock_doc = nullptr;

int usleep(useconds_t useconds) {
	cout << "Mocked usleep: It doesn't sleep anymore" << endl;

	return MockMyDOC::mock_doc->usleep(useconds);
}

TEST(SutTest, UseMock) {
	SUT sut_mock;
	MockMyDOC::mock_doc = new MockMyDOC();

	EXPECT_CALL(*MockMyDOC::mock_doc, usleep(_)).WillRepeatedly(Return(0));

	sut_mock.foo(5000000);
	delete(MockMyDOC::mock_doc);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
