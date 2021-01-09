#include <gtest/gtest.h>

bool isIsomorphic(char * s, char * t){
    int ss[128] = {0};
    int tt[128] = {0};
    int sc =0, tc = 0;
    for (int i = 0; s[i] != '\0'; i++){
        if ( ss[s[i]] == 0 ) ss[s[i]] = ++sc;
        if ( tt[t[i]] == 0 ) tt[t[i]] = ++tc;
        if ( ss[s[i]] != tt[t[i]] ) return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num205x001)
{
    bool res;
    res = isIsomorphic("egg", "add");
    EXPECT_EQ(res, true);
}

TEST(LeetCode, num205x002)
{
    bool res;
    res = isIsomorphic("foo", "bar");
    EXPECT_EQ(res, false);
}

TEST(LeetCode, num205x003)
{
    bool res;
    res = isIsomorphic("paper", "title");
    EXPECT_EQ(res, true);
}