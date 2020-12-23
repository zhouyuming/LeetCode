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