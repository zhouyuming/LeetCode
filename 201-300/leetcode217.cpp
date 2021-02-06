#include <gtest/gtest.h>
#include <math.h>

int mycmp(const void *a, const void *b)
{
    return *((int*)a) - *((int*)b);
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), mycmp);
    for (int i = 0; i < numsSize - 1; i++) {
        if  (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num217x001)
{
    int nums[4] = {1, 2, 3, 1};
    bool res = containsDuplicate(nums, 4);
    EXPECT_EQ(res, true);
}

TEST(LeetCode, num217x002)
{
    int nums[4] = {1, 2, 3, 4};
    bool res = containsDuplicate(nums, 4);
    EXPECT_EQ(res, false);
}

TEST(LeetCode, num217x003)
{
    int nums[10] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    bool res = containsDuplicate(nums, 10);
    EXPECT_EQ(res, true);
}