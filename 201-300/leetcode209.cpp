#include <gtest/gtest.h>
#include <math.h>
#include <climits>

int lower_bound(int *a, int l, int r, int q)
{
    if (a[r] < q) {
        return -1;
    }
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= q) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int minSubArrayLen(int s, int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int ans = INT_MAX;
    int *sums = (int*)malloc(sizeof(int) * (numsSize + 1));
    memset(sums, 0, sizeof(int) * (numsSize + 1));
    for (int i = 1; i <= numsSize; i++) {
        sums[i] = sums[i - 1] + nums[i - 1];
    }
    for (int i = 1; i <= numsSize; i++) {
        int target = s + sums[i - 1];
        int bound = lower_bound(sums, 1, numsSize, target);
        if (bound != -1) {
            ans = fmin(ans, bound - (i - 1));
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