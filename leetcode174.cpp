#include <gtest/gtest.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize){
    int R = dungeonSize;
    int C = *dungeonColSize;
    int dp[R][C];
    dp[R - 1][C - 1] = 1 - min(dungeon[R - 1][C - 1], 0);
    for (int i = R - 2; i >= 0; i--) {
        dp[i][C - 1] = max(dp[i + 1][C - 1] - dungeon[i][C - 1], 1);
    }
    for (int i = C - 2; i >= 0; i--) {
        dp[R - 1][i] = max(dp[R - 1][i + 1] - dungeon[R - 1][i], 1);
    }
    for (int i = R - 2; i >= 0; i--) {
        for (int j = C - 2; j >= 0; j--) {
            dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
        }
    }
    return dp[0][0];
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num174x001)
{
    int res;
    int **dungeon = (int**)malloc(3 * sizeof(int*));
    dungeon[0] = (int*)malloc(3 * sizeof(int));
    dungeon[1] = (int*)malloc(3 * sizeof(int));
    dungeon[2] = (int*)malloc(3 * sizeof(int));
    dungeon[0][0] = -2;
    dungeon[0][1] = -3;
    dungeon[0][2] = 3;
    dungeon[1][0] = -5;
    dungeon[1][1] = -10;
    dungeon[1][2] = 1;
    dungeon[2][0] = 10;
    dungeon[2][1] = 30;
    dungeon[2][2] = -5;
    int dungeonColSize[3] = {3, 3, 3};
    res = calculateMinimumHP(dungeon, 3, dungeonColSize);
    ASSERT_EQ(res, 7);
}
