#include <iostream>
#include <stack>

#include "gtest/gtest.h"

using namespace std;

TEST(StackTest, Size) {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);

	int cnt = s.size();
	for (int i = 0; i < cnt; i++)
		s.push(i);

	ASSERT_EQ(cnt * 2, s.size());
}

TEST(StackTest, Empty) {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);

	int cnt = s.size();
	for (int i = 0; i < cnt; i++)
		s.pop();

	ASSERT_TRUE(s.empty());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
