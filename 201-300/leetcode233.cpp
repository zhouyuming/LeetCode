#include <gtest/gtest.h>

int countDigitOne(int n){
    int countr = 0;
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        countr += (n / divider) * i + fmin(fmax(n % divider - i + 1, 0), i);
    }
    return countr;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num233x001)
{

}