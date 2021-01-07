#include <gtest/gtest.h>

uint32_t reverseBits(uint32_t n) {
    long result;
    for (int i = 0; i < 32; i++) {
        result = result * 2 + n % 2;
        n /= 2;
    }
    return result;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num190x001)
{
    unsigned int res;
    res = reverseBits(43261596);
    EXPECT_EQ(res, 964176192);
}