#include <gtest/gtest.h>


int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int num[100];
    memset(num, 0, sizeof(num));
    int ret = 0;
    for (int i = 0; i < dominoesSize; i++) {
        int val = dominoes[i][0] < dominoes[i][1] ? dominoes[i][0] * 10 + dominoes[i][1] : dominoes[i][1] * 10 + dominoes[i][0];
        ret += num[val];
        num[val]++;
    }
    return ret;
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num1128x001)
{

}