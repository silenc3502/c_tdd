#include "gtest/gtest.h"

#include "HL_sys_common.h"
#include "HL_gio.h"

TEST(AddTest, onePlusTwoGivesThree) {
	EXPECT_EQ(3, add(1, 2));
}

TEST(gioSetDirection, 

/*
gioInit();
    gioSetDirection(gioPORTA, 0xffffffff);
    gioSetPort(gioPORTA, 0xffffffff);
    gioSetBit(gioPORTA, 4, 1);
*/

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

