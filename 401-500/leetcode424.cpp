#include <gtest/gtest.h>
#include <math.h>

int characterReplacement(char * s, int k){
    int num[26];
    memset(num, 0, sizeof(num));
    int n = strlen(s);
    int left = 0;
    int right = 0;
    int maxn = 0;
    while (right < n) {
        num[s[right] - 'A']++;
        maxn = fmax(maxn, num[s[right] - 'A']);
        if (right - left + 1 - maxn > k) {
            num[s[left] - 'A']--;
            left++;
        }
        right++;
    }
    return right - left;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num424x001)
{
    int res = characterReplacement((char*)"ABAB", 2);
    EXPECT_EQ(res, 4);
}

TEST(LeetCode, num424x002)
{
    int res = characterReplacement((char*)"AABABBA", 1);
    EXPECT_EQ(res, 4);
}