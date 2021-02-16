#include <gtest/gtest.h>

int arrayPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), mycmp);
    int ans = 0;
    for (int i = 0; i < numsSize; i += 2) {
        ans += nums[i];
    }
    return ans;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num561x001)
{

}