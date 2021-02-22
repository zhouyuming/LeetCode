#include <gtest/gtest.h>

#define MIN(a, b) ((a < b) ? (a) : (b))

int min(int a, int b, int c)
{
    int ret;
    ret = MIN(a, b);
    ret = MIN(ret, c);
    return ret;
}

int nthUglyNumber(int n){
    int dp[n];
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = min(dp[i2] * 2, dp[i3] * 3, dp[i5] * 5);
        if (dp[i] == dp[i2] * 2) {
            i2++;
        }

        if (dp[i] == dp[i3] * 3) {
            i3++;
        }

        if (dp[i] == dp[i5] * 5) {
            i5++;
        }
    }
    return dp[n - 1];
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num264x001)
{

}