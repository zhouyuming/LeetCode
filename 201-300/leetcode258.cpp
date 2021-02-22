#include <gtest/gtest.h>

int addDigits(int num){
    int res = 0;
    while (num) {
        res = res + num % 10;
        num = num / 10;
    }
    if (res >= 10) {
        return addDigits(res);
    } 
    return res;   
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num258x001)
{

}