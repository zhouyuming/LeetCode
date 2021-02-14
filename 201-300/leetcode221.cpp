#include <gtest/gtest.h>

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int maxSide = 0;
    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL) {
        return maxSide;
    }
    int **dp = (int**)malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++) {
        dp[i] = (int*)malloc(sizeof(int) * matrixColSize[0]);
        memset(dp[i], 0, sizeof(int) * matrixColSize[0]);
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = fmin(fmin(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                maxSide = fmax(dp[i][j], maxSide);
            }
        }
    }
    return maxSide * maxSide;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num221x001)
{
    int nums[4] = {1, 2, 3, 1};
    bool res = containsNearbyAlmostDuplicate(nums, 4, 3, 0);
    EXPECT_EQ(res, true);
}