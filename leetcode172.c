#include <gtest/gtest.h>

int trailingZeroes(int n)
{
    int res=0;
    do{
        res+=n/5;
        n=n/5;
    }while(n>0);
    return res;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num172x001)
{
    int res;
    res = trailingZeroes(3);
    ASSERT_EQ(res, 0);
}


TEST(LeetCode, num172x002)
{
    int res;
    res = trailingZeroes(5);
    ASSERT_EQ(res, 1);
}