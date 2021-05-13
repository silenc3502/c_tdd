#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

TEST (MatcherTest, Containers) {
	vector<int> vec { 1, 2, 3, 4, 5 };

	EXPECT_THAT(vec, BeginEndDistanceIs(Le(5)));
	EXPECT_THAT(vec, SizeIs(Le(5)));
	EXPECT_THAT(vec, IsEmpty());
	EXPECT_THAT(vec, Contains(5));
	EXPECT_THAT(vec, Each(Ge(1)));
	EXPECT_THAT(vec, ContainerEq(vec));
}

TEST (MatcherTest2, Containers) {
	vector<int> vec_asc { 1, 2, 3, 4, 5 };
	vector<int> vec_desc { 5, 4, 3, 2, 1 };

	EXPECT_THAT(vec_asc, WhenSorted(ContainerEq(vec_asc)));
	EXPECT_THAT(vec_asc, WhenSortedBy(greater<int>(), ContainerEq(vec_desc)));
	EXPECT_THAT(vec_asc, IsSubsetOf({ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }));
	EXPECT_THAT(vec_asc, IsSupersetOf({ 3, 2, 1 }));
}

TEST (MatcherTest3, Containers) {
	vector<int> vec_asc { 1, 2, 3, 4, 5 };
	vector<int> vec_desc { 5, 4, 3, 2, 1 };

	EXPECT_THAT(vec_asc, Pointwise(Eq(), vec_asc));
	EXPECT_THAT(vec_asc, UnorderedPointwise(Eq(), vec_desc));
	EXPECT_THAT(vec_asc, ElementsAre(Ge(1), Ge(2), Ge(3), Ge(4), Ge(5)));
	EXPECT_THAT(vec_asc, UnorderedElementsAre(Ge(5), Ge(4), Ge(3), Ge(2), Ge(1)));

	vector<Matcher<int>> vec_m_asc { Ge(1), Ge(2), Ge(3), Ge(4), Ge(5) };
	vector<Matcher<int>> vec_m_dsc { Ge(5), Ge(4), Ge(3), Ge(2), Ge(1) };

	EXPECT_THAT(vec_asc, ElementsAreArray(vec_m_asc));
	EXPECT_THAT(vec_asc, UnorderedElementsAreArray(vec_m_dsc));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
