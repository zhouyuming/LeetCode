#include <gtest/gtest.h>

bool isAnagram(char * s, char * t){
    int cnt1 = strlen(s);
    int cnt2 = strlen(t);
    int alpha[26] = {0};

    if (cnt1 != cnt2) {
        return false;
    }
    for (int i = 0; i < cnt1; i++) {
        alpha[s[i] - 'a']++;
    }
    for (int i = 0; i < cnt2; i++) {
        alpha[t[i] - 'a']--;
        if (alpha[t[i] - 'a'] < 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num242x001)
{

}