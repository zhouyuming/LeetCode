#include <gtest/gtest.h>

int mycmp(const void* a, const void* b)
{
    return *((int*)a) < *((int*)b) ? -1 : 1;
}

int* singleNumber(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    if (nums == NULL || numsSize == 0) {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), mycmp);
    int *res = (int*)malloc(sizeof(int) * numsSize);
    if (numsSize == 1) {
        res[(*returnSize)++] = nums[0];
        return res;
    }
    if (nums[0] != nums[1]) {
        res[(*returnSize)++] = nums[0];    
    }
    for (int i = 1; i < numsSize - 1; i++) {
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
            res[(*returnSize)++] = nums[i];
        }
    }
    if (nums[numsSize - 1] != nums[numsSize - 2]) {
        res[(*returnSize)++] = nums[numsSize - 1];    
    }
    return res;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num260x001)
{

}