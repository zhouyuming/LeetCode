#include <gtest/gtest.h>

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

int findMaxForm(char ** strs, int strsSize, int m, int n)
{
    int cnt0[strsSize];
    int cnt1[strsSize];
    memset(cnt0, 0, sizeof(int) * strsSize);
    memset(cnt1, 0, sizeof(int) * strsSize);

    for (int i = 0; i < strsSize; i++) {
        int len = strlen(strs[i]);
        int cnt = 0;
        for (int j = 0; j < len; j++) {
            if (strs[i][j] == '0') {
                cnt++;
            }
        }
        cnt0[i] = cnt;
        cnt1[i] = len - cnt;
    }
    int dp[m + 1][n + 1];
    memset(&dp, 0, sizeof(int) * (m + 1) * (n + 1));
    for (int i = 0; i < strsSize; i++) {
        for (int j = m; j >= cnt0[i]; j--) {
            for (int k = n; k >= cnt1[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - cnt0[i]][k - cnt1[i]] + 1);
            }
        }
    }
    return dp[m][n];
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num474x001)
{
    char* s[5] = {"10", "0001", "111001", "1", "0"};
    int res = findMaxForm(s, 5, 5, 3);
    EXPECT_EQ(res, 4);
}

TEST(LeetCode, num474x002)
{
    char* s[3] = {"10", "0", "1"};
    int res = findMaxForm(s, 3, 1, 1);
    EXPECT_EQ(res, 2);
}