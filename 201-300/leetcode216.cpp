#include <gtest/gtest.h>

#define MAX_SIZE 100

void dfs(int k, int n, int* returnSize, int ***ans, int index, int num, int *temp)
{
    temp[index] = num;
    if (index == k - 1) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += temp[i];
        }
        if (sum == n) {
            memcpy((*ans)[*returnSize], temp, sizeof(int) * k);
            (*returnSize)++;
            (*ans)[*returnSize] = (int*)malloc(sizeof(int) * k);
            memset((*ans)[*returnSize], 0, sizeof(int) * k);
        }
        return;   
    }
    for (int i = num + 1; i <= 11 - k + index; i++) {
        dfs(k, n, returnSize, ans, index + 1, i, temp);
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    int **ans = (int**)malloc(sizeof(int*) * MAX_SIZE);
    int *temp = (int*)malloc(sizeof(int) * k);
    memset(temp, 0, sizeof(int) * k);
    *returnSize = 0;
    ans[*returnSize] = (int*)malloc(sizeof(int) * k);
    memset(ans[*returnSize], 0, sizeof(int) * k);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX_SIZE);
    memset(*returnColumnSizes, 0, sizeof(int) * MAX_SIZE);
    for (int i = 1; i <= 10 - k; i++) {
        dfs(k, n, returnSize, &ans, 0, i, temp);
    }
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }
    return ans;    
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num216x001)
{
    int **res = NULL;
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    res = combinationSum3(3, 7, &returnSize, &returnColumnSizes);
    EXPECT_EQ(returnSize, 1);
}