#include <gtest/gtest.h>

int cmp(char c)
{
    char *s1 = "qwertyuiopQWERTYUIOP";
    char *s2 = "asdfghjklASDFGHJKL";
    char *s3 = "zxcvbnmZXCVBNM";

    if (strchr(s1, c) != NULL) {
        return 1;
    } else if (strchr(s2, c) != NULL) {
        return 2;
    }
    return 3;
}

char ** findWords(char ** words, int wordsSize, int* returnSize){
    char **ret = (char **)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        int flag = cmp(words[i][0]);
        for (int j = 1; j < len; j++) {
            if (cmp(words[i][j]) != flag) {
                flag = -1;
                break;
            }
        }
        if (flag != -1) {
            ret[*returnSize] = (char *)malloc((len + 1) * sizeof(char));
            memcpy(ret[*returnSize], words[i], len + 1);
            (*returnSize)++;
        }
    }
    return ret;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num500x001)
{
    
    EXPECT_EQ(res, true);
}