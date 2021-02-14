#include <gtest/gtest.h>

void add()
{
    
}

int minSwapsCouples(int* row, int rowSize){
    int n = rowSize;
    int tot = n / 2;
    int f[tot];

    memset(f, 0, sizeof(f));
    for (int i = 1; i < tot; i++) {
        f[i] = i;
    }

    for (int i = 0; i < n; i += 2) {
        int l = row[i] / 2;
        int r = row[i + 1] / 2;
        add(f, l, r);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num765x001)
{

}