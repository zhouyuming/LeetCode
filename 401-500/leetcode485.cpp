#include <gtest/gtest.h>

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int cnt = 0;
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            cnt++;
        } else {
            if (cnt > max) max = cnt;
            cnt = 0;
        }
    }
    if (cnt > max) max = cnt;
    return max;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num485x001)
{
    int nums[6] = {1, 1, 0, 1, 1, 1};
    int res = findMaxConsecutiveOnes(nums, 6);
    EXPECT_EQ(res, 3);
}