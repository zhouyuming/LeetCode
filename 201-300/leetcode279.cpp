int numSquares(int n){
    int* dp = (int*)malloc(sizeof(int) * (n + 1));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
    }
    for (int i = 1, sqr = i * i; sqr <= n; ++i, sqr = i * i) {
        for (int j = sqr; j <= n; j++) {
            dp[j] = fmin(dp[j], dp[j - sqr] + 1);
        }
    }
    return dp[n];
}