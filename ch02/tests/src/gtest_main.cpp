#include <iostream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

#include "sut.h"
#include "mock.h"

TEST(SutTest, FirstTest) {
	MockDOC mock_doc;
	SUT mock_sut(mock_doc);

	EXPECT_CALL(mock_doc, foo()).WillRepeatedly(DoAll(Return(0)));

	if (mock_sut.foo())
		std::cout << "Product" << std::endl;
	else
		std::cout << "GoogleTest" << std::endl;

	ASSERT_FALSE(mock_sut.foo());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
