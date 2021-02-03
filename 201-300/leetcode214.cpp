#include <gtest/gtest.h>

char* shortestPalindrome(char* s) {
    int n = strlen(s);
    int fail[n + 1];

    memset(fail, -1, sizeof(fail));
    for (int i = 1; i < n; ++i) {
        int j = fail[i - 1];
        while (j != -1 && s[j + 1] != s[i]) {
            j = fail[j];
        }
        if (s[j + 1] == s[i]) {
            fail[i] = j + 1;
        }
    }
    int best = -1;
    for (int i = n - 1; i >= 0; i--) {
        while (best != -1 && s[best + 1] != s[i]) {
            best = fail[best];
        }
        if (s[best + 1] == s[i]) {
            best++;
        }
    }
    int ret_len = n - best - 1;
    char *ret = (char*)malloc(sizeof(char) * (ret_len + n + 1));
    for (int i = 0; i < ret_len; i++) {
        ret[i] = s[n - i - 1];
    }
    for (int i = 0; i < n; i++) {
        ret[i + ret_len] = s[i];
    }
    ret[ret_len + n] = 0;
    return ret;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num214x001)
{
    char *temp = shortestPalindrome((char*)"aacecaaa");
    EXPECT_EQ(strcmp(temp, (char*)"aaacecaaa"), 0);
}

TEST(LeetCode, num214x002)
{
    char *temp = shortestPalindrome((char*)"abcd");
    EXPECT_EQ(strcmp(temp, (char*)"dcbabcd"), 0);
}