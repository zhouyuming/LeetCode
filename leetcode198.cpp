#include <gtest/gtest.h>

int rob(int* nums, int numsSize){
    if (!numsSize) {
        return 0;
    }

    int dp[numsSize][2];
    dp[0][0] = 0;
    dp[0][1] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i][0] = dp[i - 1][0] > dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1];
        dp[i][1] = nums[i] + dp[i - 1][0];
    }
    return dp[numsSize - 1][0] > dp[numsSize - 1][1] ? dp[numsSize - 1][0] : dp[numsSize - 1][1];
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num198x001)
{
    int res;
    int nums[4] = {1, 2, 3, 1};
    res = rob(nums, 4);
    EXPECT_EQ(res, 4);
}

TEST(LeetCode, num198x002)
{
    int res;
    int nums[5] = {2, 7, 9, 3, 1};
    res = rob(nums, 5);
    EXPECT_EQ(res, 12);
}