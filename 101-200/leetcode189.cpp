#include <gtest/gtest.h>

void reverseBuf(int* nums, int numsSize)
{
    int i = 0;
    int temp = 0;

    for (i = 0; i < numsSize / 2; i++) {
        temp = nums[i];
        nums[i] = nums[numsSize - i - 1];
        nums[numsSize - i - 1] = temp;
    }
    return;
}

void rotate(int* nums, int numsSize, int k) {
    if (nums == NULL || numsSize <= 1) {
        return;
    }

    k = k % numsSize;

    reverseBuf(&nums[0], numsSize);
    reverseBuf(&nums[0], k);
    reverseBuf(&nums[k], numsSize - k);
    return;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num189x001)
{
    int res;
    int test[7] = {1, 2, 3, 4, 5, 6, 7};
    rotate(test, 7, 3);
    EXPECT_EQ(test[0], 5);
    EXPECT_EQ(test[1], 6);
    EXPECT_EQ(test[2], 7);
    EXPECT_EQ(test[3], 1);
    EXPECT_EQ(test[4], 2);
    EXPECT_EQ(test[5], 3);
    EXPECT_EQ(test[6], 4);
}