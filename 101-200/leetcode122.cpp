#include <gtest/gtest.h>

int maxProfit(int* prices, int pricesSize){
    int i;
    int profit = 0;
    if (pricesSize == 0) return 0;

    for (i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num122x001)
{
    int res;
    int prices[6] = {7, 1, 5, 3, 6, 4};
    res = maxProfit(prices, 6);
    ASSERT_EQ(res, 7);
}

TEST(LeetCode, num122x002)
{
    int res;
    int prices[5] = {1, 2, 3, 4, 5};
    res = maxProfit(prices, 5);
    ASSERT_EQ(res, 4);
}

TEST(LeetCode, num122x003)
{
    int res;
    int prices[5] = {7, 6, 4, 3, 1};
    res = maxProfit(prices, 5);
    ASSERT_EQ(res, 0);
}