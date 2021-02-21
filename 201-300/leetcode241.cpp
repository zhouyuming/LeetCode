#include <gtest/gtest.h>

#define MAX_SIZE 10000

int* dfs(char* input, int inputSize, int* returnSize)
{
    int* res = (int*)malloc(sizeof(int) * MAX_SIZE);
    *returnSize = 0;
    for (int i = 0; i < inputSize; i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
            int leftSize = 0;
            int* left = dfs(input, i, &leftSize);
            int rightSize = 0;
            int* right = dfs(input + i + 1, inputSize - i - 1, &rightSize);
            for (int l = 0; l < leftSize; l++) {
                for (int r = 0; r < rightSize; r++) {
                    if (input[i] == '+') {
                        res[(*returnSize)++] = left[l] + right[r];
                    } else if (input[i] == '-') {
                        res[(*returnSize)++] = left[l] - right[r];
                    } else if (input[i] == '*') {
                        res[(*returnSize)++] = left[l] * right[r];
                    }
                }
            }
        }
    }
    if (*returnSize == 0) {
        int tmp = 0;
        for (int i = 0; i < inputSize; i++) {
            tmp = tmp * 10 + (input[i] - '0');
        }
        res[(*returnSize)++] = tmp;
    }
    return res;
}

int* diffWaysToCompute(char * input, int* returnSize){
    return dfs(input, strlen(input), returnSize);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num241x001)
{

}
