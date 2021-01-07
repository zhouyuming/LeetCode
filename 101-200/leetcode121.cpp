#include <gtest/gtest.h>
#include <math.h>

int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize == 0) {
        return 0;
    }
    int f[pricesSize][2];
    f[0][0] = -prices[0];
    f[0][1] = 0;
    for (int i = 1; i < pricesSize; i++) {
        f[i][0] = fmax(-prices[i], f[i - 1][0]);
        f[i][1] = fmax(f[i - 1][0] + prices[i], f[i - 1][1]);
    }
    return f[pricesSize - 1][1];
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num121x001)
{
    int res;
    int prices[6] = {7, 1, 5, 3, 6, 4};
    res = maxProfit(prices, 6);
    ASSERT_EQ(res, 5);
}

TEST(LeetCode, num121x002)
{
    int res;
    int prices[5] = {7, 6, 4, 3, 1};
    res = maxProfit(prices, 5);
    ASSERT_EQ(res, 0);
}