#include <gtest/gtest.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize){

    int *answer = (int*)malloc(sizeof(int) * numsSize);
    memset(answer, 0, sizeof(int) * numsSize);
    answer[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    int R = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] = answer[i] * R;
        R *= nums[i];
    }
    *returnSize = numsSize;
    return answer;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num238x001)
{

}
