#include <iostream>
#include <stack>

#include "gtest/gtest.h"

using namespace std;

class StackTest : public ::testing::Test {
protected:
	stack<int> s;

	void SetUp() override {
		s.push(1);
		s.push(2);
		s.push(3);
	}

	void TearDown() override {}
};

TEST_F(StackTest, Size) {
	int cnt = s.size();

	for (int i = 0; i < cnt; i++)
		s.push(i);

	ASSERT_EQ(cnt * 2, s.size());
}

TEST_F(StackTest, Empty) {
	int cnt = s.size();

	for (int i = 0; i < cnt; i++)
		s.pop();

	ASSERT_TRUE(s.empty());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
