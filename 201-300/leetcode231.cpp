#include <gtest/gtest.h>

bool isPowerOfTwo(int n){
    if (n == 0) {
        return false;
    }
    long x = n;
    return (x & (x - 1)) == 0;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num231x001)
{

}