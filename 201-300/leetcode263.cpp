#include <gtest/gtest.h>

bool isUgly(int num){
    if (num == 0) {
        return false;
    }
    while (num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
        if (num % 2 == 0) {
            num /= 2;
        } else if (num % 3 == 0) {
            num /= 3;
        } else if (num % 5 == 0) {
            num /= 5;
        }
    }
    if (num == 1) {
        return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num263x001)
{

}