#include <gtest/gtest.h>

int mycmp(const void *a, const void *b)
{
    return *((int*)a) - *((int*)b);
}

int maximumProduct(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), mycmp);
    int zeronum = 0;
    int posinum = 0;
    int neganum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            zeronum++;
        } else if (nums[i] > 0) {
            posinum++;
        } else {
            neganum++;
        }
    }
    int num1 = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    int num2 = nums[0] * nums[1] * nums[numsSize - 1];
    if (neganum <= 1) {
        return num1;
    } else {
        return num1 > num2 ? num1 : num2;
    } 
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num628x001)
{
    int nums[3] = {1, 2, 3};
    int res = maximumProduct(nums, 3);
    EXPECT_EQ(res, 6);
}

TEST(LeetCode, num628x002)
{
    int nums[4] = {1, 2, 3, 4};
    int res = maximumProduct(nums, 4);
    EXPECT_EQ(res, 24);
}

TEST(LeetCode, num628x003)
{
    int nums[3] = {-1, -2, -3};
    int res = maximumProduct(nums, 3);
    EXPECT_EQ(res, -6);
}