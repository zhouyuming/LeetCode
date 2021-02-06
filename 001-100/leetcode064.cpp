#include <gtest/gtest.h>

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int** res = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        res[i] = (int*)malloc(gridColSize[i] * sizeof(int));
        memset(res[i], 0, gridColSize[i] * sizeof(int));
    }
    int sum = 0;
    for (int i = 0; i < gridColSize[0]; i++) {
        sum = sum + grid[0][i];
        res[0][i] = sum;
    }
    sum = 0;
    for (int i = 0; i < gridSize; i++) {
        sum = sum + grid[i][0];
        res[i][0] = sum;
    }

    for (int i = 1; i < gridSize; i++) {
        for (int j = 1; j < gridColSize[0]; j++) {
            res[i][j] = (res[i - 1][j] > res[i][j - 1] ? res[i][j - 1] : res[i - 1][j]) + grid[i][j];
        }
    }
    return res[gridSize - 1][gridColSize[0] - 1];    
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num064x001)
{
    
    EXPECT_EQ(res, true);
}