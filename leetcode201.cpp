#include <gtest/gtest.h>

int rangeBitwiseAnd(int m, int n){
    int shift = 0;
    while (m < n) {
        n &= (n - 1);
    }
    return n;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num201x001)
{
    int res;
    res = rangeBitwiseAnd(5, 7);
    EXPECT_EQ(res, 4);
}

TEST(LeetCode, num201x002)
{
    int res;
    res = rangeBitwiseAnd(0, 1);
    EXPECT_EQ(res, 0);
}