#include <gtest/gtest.h>

#define MAX(x, y) (x) > (y) ? (x) : (y)

int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize == 0) {
        return 0;
    }
    int dp[pricesSize][3][2];
    memset(dp, 0, sizeof(dp));
    for (int k = 1; k < 3; k++) {
        dp[0][k][0] = 0;
        dp[0][k][1] = -prices[0];
    }
    for (int i = 1; i < pricesSize; i++) {
        for (int k = 1; k < 3; k++) {
            dp[i][k][0] = MAX(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
            dp[i][k][1] = MAX(dp[i-1][k][1], dp[i-1][k - 1][0] - prices[i]);
        }
    }
    return dp[pricesSize - 1][2][0];
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num123x001)
{
    int res;
    int prices[8] = {3, 3, 5, 0, 0, 3, 1, 4};
    res = maxProfit(prices, 8);
    ASSERT_EQ(res, 6);
}

TEST(LeetCode, num123x002)
{
    int res;
    int prices[5] = {1, 2, 3, 4, 5};
    res = maxProfit(prices, 5);
    ASSERT_EQ(res, 4);
}

TEST(LeetCode, num123x003)
{
    int res;
    int prices[5] = {7, 6, 4, 3, 1};
    res = maxProfit(prices, 5);
    ASSERT_EQ(res, 0);
}