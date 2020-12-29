#include <gtest/gtest.h>

int hammingWeight(uint32_t n) {
    int num = 0;
    while (n) {
        if (n % 2) {
            num++;
        }
        n /= 2;
    }
    return num;   
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num191x001)
{
    int res;
    res = hammingWeight(2);
    EXPECT_EQ(res, 1);
}