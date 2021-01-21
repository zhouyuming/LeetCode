#include <gtest/gtest.h>

#define MAX(a, b) ((a)>(b)?(a):(b))

int rob(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    int a[numsSize];
    int b[numsSize];

    a[0] = nums[0];
    a[1] = nums[0];
    b[0] = 0;
    b[1] = nums[1];

    for (int i = 2; i < numsSize; i++) {
        a[i] = MAX(a[i - 1], a[i - 2] + nums[i]);
        b[i] = MAX(b[i - 1], b[i - 2] + nums[i]);
    }
    return MAX(a[numsSize - 2], b[numsSize - 1]);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num213x001)
{
    int res;
    int nums[3] = {2, 3, 2};
    res = rob(nums, 3);
    EXPECT_EQ(res, 3);
}

TEST(LeetCode, num213x002)
{
    int res;
    int nums[4] = {1, 2, 3, 1};
    res = rob(nums, 4);
    EXPECT_EQ(res, 4);
}

TEST(LeetCode, num213x003)
{
    int res;
    int nums[1] = {0};
    res = rob(nums, 1);
    EXPECT_EQ(res, 0);
}