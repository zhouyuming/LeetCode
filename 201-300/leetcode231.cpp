#include <gtest/gtest.h>

bool isPowerOfTwo(int n){
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1 <<i)) {
            cnt++;
            if (cnt > 1) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num231x001)
{

}