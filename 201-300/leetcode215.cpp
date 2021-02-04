#include <gtest/gtest.h>

int mycmp(const void *a, const void *b)
{
    return *((int*)b) - *((int*)a);
}

int findKthLargest(int* nums, int numsSize, int k){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), mycmp);
    return nums[k - 1];
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num215x001)
{
    int arr[6] = {3, 2, 1, 5, 6, 4};
    EXPECT_EQ(findKthLargest(arr, 6, 2), 5);
}

TEST(LeetCode, num215x002)
{
    int arr[9] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    EXPECT_EQ(findKthLargest(arr, 9, 4), 4);
}