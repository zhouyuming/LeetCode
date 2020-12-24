#include <gtest/gtest.h>

int mycmp(const void* a, const void* b)
{
    char s1[100];
    char s2[100];
    sprintf(s1, "%d%d", *(int*)a, *(int*)b);
    sprintf(s2, "%d%d", *(int*)b, *(int*)a);
    return strcmp(s2, s1);
}

char * largestNumber(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), mycmp);
    if (nums[0] == 0) {
        return 0;
    }
    char* result = NULL;
    char* p = NULL;
    result = (char*)malloc(sizeof(char) * 1000);
    p = result;
    for (int i = 0; i < numsSize; i++) {
        sprintf(p, "%d", nums[i]);
        p += strlen(p);
    }
    return result;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num179x001)
{
    char* res = NULL;
    int nums[2] = {10, 2};
    res = largestNumber(nums, 2);
    int r = strcmp(res, "210");
    ASSERT_EQ(r, 0);
}

TEST(LeetCode, num179x002)
{
    char* res = NULL;
    int nums[5] = {3, 30, 34, 5, 9};
    res = largestNumber(nums, 5);
    int r = strcmp(res, "9534330");
    ASSERT_EQ(r, 0);
}

TEST(LeetCode, num179x003)
{
    char* res = NULL;
    int nums[1] = {1};
    res = largestNumber(nums, 1);
    int r = strcmp(res, "1");
    ASSERT_EQ(r, 0);
}

TEST(LeetCode, num179x004)
{
    char* res = NULL;
    int nums[1] = {10};
    res = largestNumber(nums, 1);
    int r = strcmp(res, "10");
    ASSERT_EQ(r, 0);
}