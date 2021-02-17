#include <gtest/gtest.h>

int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    if (nums == NULL || numsSize == 0 || numsColSize[0] == 0) {
        return NULL;
    }
    if (numsSize * numsColSize[0] != r * c) {
        *returnSize = numsSize;
        *returnColumnSizes = numsColSize;
        return nums;
    }
    int **ret = (int**)malloc(sizeof(int*) *  (numsSize * numsColSize[0]) / c);
    *returnSize = 0;
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            if (cnt == 0) {
                ret[(*returnSize)] = (int*)malloc(sizeof(int) * c);
            }
            ret[(*returnSize)][cnt++] = nums[i][j];
            if (cnt == c) {
                (*returnSize)++;
                cnt = 0;
            }
        }
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
    }
    return ret;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num566x001)
{
    
}
