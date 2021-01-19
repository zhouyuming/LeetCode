#include <gtest/gtest.h>
#include <math.h>
#include <climits>

/*int minSubArrayLen(int s, int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            if (sum >= s) {
                ans = fmin(ans, j - i + 1);
                break;
            }
        }
    }
    return ans == INT_MAX ? 0 : ans;
}*/

int minSubArrayLen(int s, int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            if (sum >= s) {
                ans = fmin(ans, j - i + 1);
                break;
            }
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num209x001)
{
    int res;
    int nums[6] = {2, 3, 1, 2, 4, 3};
    res = minSubArrayLen(7, nums, 6);
    EXPECT_EQ(res, 2);
}