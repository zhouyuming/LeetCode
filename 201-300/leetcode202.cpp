#include <gtest/gtest.h>

int reverse(int n)
{
    int num = 0;
    while (n != 0) {
        num = num + (n % 10) * (n % 10);
        n = n / 10;
    }
    return num;
}

bool isHappy(int n)
{
    int num = 0;
    int *hash = (int*)calloc(sizeof(int), 820);
    num = reverse(n);
    while (num != 1) {
        if (hash[num] == 1) {
            return false;
        } else {
            hash[num]++;
        }
        num = reverse(num);
    }
    return true;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num202x001)
{
    bool res;
    res = isHappy(19);
    EXPECT_EQ(res, true);
}