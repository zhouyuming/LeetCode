#include <gtest/gtest.h>

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t){
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j <= i + k && j < numsSize; j++) {
            if (abs(nums[i] - nums[j]) <= t) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num220x001)
{
    int nums[4] = {1, 2, 3, 1};
    bool res = containsNearbyAlmostDuplicate(nums, 4, 3, 0);
    EXPECT_EQ(res, true);
}

TEST(LeetCode, num220x002)
{
    int nums[4] = {1, 0, 1, 1};
    bool res = containsNearbyAlmostDuplicate(nums, 4, 1, 2);
    EXPECT_EQ(res, true);
}

TEST(LeetCode, num220x003)
{
    int nums[6] = {1, 5, 9, 1, 5, 9};
    bool res = containsNearbyAlmostDuplicate(nums, 6, 2, 3);
    EXPECT_EQ(res, false);
}