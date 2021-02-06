#include <gtest/gtest.h>

int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < ASize; i++) {
        sum1 += A[i];
    }
    for (int i = 0; i < BSize; i++) {
        sum2 += B[i];
    }
    int *ans = (int*)malloc(2 * sizeof(int));
    memset(ans, 0, 2 * sizeof(int));
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < BSize; j++) {
            if ((A[i] - B[j]) * 2 == sum1 - sum2) {
                ans[0] = A[i];
                ans[1] = B[j];
                *returnSize = 2;
                return ans;
            }
        }
    }
    *returnSize = 0;
    return ans;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num888x001)
{

}