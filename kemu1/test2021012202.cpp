/*
给定两个数，字符串形式如“4312”“13”，将第二个数插入到第一个数中（第二个数为一个整体不能分割去插），使其值最大，“43132”为最大值
限制第一个数无前缀0，构造出来的数unsigned long long存不了（所以肯定是拼字符串了）
*/

#include <gtest/gtest.h>

char *InsertDigit(char *score, char *digit)
{
    int len = strlen(score) + strlen(digit) + 1;
    char *res = (char *)malloc(len);
    if (res == NULL) {
        return NULL;
    }
    (void)memset_s(res, len, 0, len);
    int j = 0;
    for (j = 0; j < strlen(score); j++) {
        int cmp = strncmp(digit, score + j, fmin(strlen(digit), strlen(score) - j));
        if (cmp > 0) {
            strcat(res, digit);
            strcat(res, &score[j]);
            break;
        } else {
            res[j] = score[j];
        }
    }
    if (j == strlen(score)) {
        strcat(res, digit);
    }
    return res;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, test001)
{
    
    EXPECT_EQ(res[0], 0);
}