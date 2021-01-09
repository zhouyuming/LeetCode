#include <gtest/gtest.h>

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimes(int n)
{
    int nums = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            nums++;
        }
    }
    return nums;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num204x001)
{
    int res;
    res = countPrimes(10);
    EXPECT_EQ(res, 4);
}

TEST(LeetCode, num204x002)
{
    int res;
    res = countPrimes(0);
    EXPECT_EQ(res, 0);
}

TEST(LeetCode, num204x003)
{
    int res;
    res = countPrimes(1);
    EXPECT_EQ(res, 0);
}