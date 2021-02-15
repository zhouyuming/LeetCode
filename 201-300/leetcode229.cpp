#include <gtest/gtest.h>

int* majorityElement(int* nums, int numsSize, int* returnSize){
    int key1 = 0;
    int key2 = 0;
    int count1 = 0;
    int count2 = 0;
    int *result = (int*)malloc(sizeof(int) * 2);

    *returnSize = 0;
    memset(result, 0, sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == key1) {
            count1++;
        } else if (nums[i] == key2) {
            count2++;
        } else if (count1 == 0) {
            key1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            key2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == key1) {
            count1++;
        } else if (nums[i] == key2) {
            count2++;
        }
    }
    if (count1 > numsSize / 3) {
        result[(*returnSize)++] = key1;
    }
    if (count2 > numsSize / 3) {
        result[(*returnSize)++] = key2;
    }
    return result;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num229x001)
{

}