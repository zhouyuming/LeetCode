#include <gtest/gtest.h>

int lastStoneWeight(int* stones, int stonesSize){
    int i;
    int j;
    int tmp;
    if (stonesSize == 1) return stones[0];
    for (i = 0; i < stonesSize - 1; i++) {
        for (j = i + 1; j < stonesSize; j++) {
            if (stones[j] > stones[i]) {
                tmp = stones[i];
                stones[i] = stones[j];
                stones[j] = tmp;
            }
        }
    }
    if (stones[1] == 0) return stones[0];
    stones[0] -= stones[1];
    stones[1] = 0;
    return lastStoneWeight(stones, stonesSize);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num1046x001)
{
    int nums[6] = {2, 7, 4, 1, 8, 1};
    int res = lastStoneWeight(nums, 6);
    EXPECT_EQ(res, 1);
}