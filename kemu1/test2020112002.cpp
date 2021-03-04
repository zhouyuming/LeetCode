/*
2、统计看到的山峰的总数
题目描述：
给定一个数组height【N】，里面从左到右依次存放着编号为1~N的山峰的海拔高度；现在科研人员依次站在这N座山峰上，若科研人员站在编号为奇数的山峰上，则科研人员向左看，统计改山峰可以看到的其他山峰的个数，若站在编号为偶数的山峰上，则向右看，统计改山峰可以看到的其他山峰的个数，最后计算科研人员可以看到的山峰个数的总数。
注：
1）站在第一座山峰上，由于向左看没有山峰，所以第一座看到的山峰个数为0；若最后一座向右看时也是如此；
2）海拔高的山峰可以挡住海拔低的山峰；
3）海拔高度一样也可以被挡住。

具体测试用例
【16,5,3,10,21,7】
16：向左看，没有山峰，所以个数为0；
5：向右看，可以依次看到高度为3,10,21的山峰，所以个数为3；
3：向左看，可以依次看到高度为5,16的山峰，所以个数为2；
10：向右看，只能看到高度为21的山峰，所以个数为1；
21：向左看，可以依次看到高度为10,16的山峰，所以个数为2；
7：向右看，没有山峰，所以个数为0；
则最终看到的总个数为0+3+2+1+2+0=8，返回8。
*/
#include <gtest/gtest.h>

int NumberOfMountainSeen(int* height, int heightSize)
{
    int* nums = (int*)malloc(sizeof(int) * heightSize);
    int* left = (int*)malloc(sizeof(int) * heightSize);
    int* right = (int*)malloc(sizeof(int) * heightSize);
    int numsSize = 0;
    int total = 0;
    
    right[heightSize - 1] = 0;
    for (int i = heightSize - 2; i >= 0; i--) {
        if (numsSize == 0) {
            nums[numsSize] = height[i + 1];
        } else {
            while ((numsSize > 0) && (height[i + 1] > nums[numsSize - 1])) {
                numsSize--;
            }
            nums[numsSize] = height[i + 1];
        }
        numsSize++;
        right[i] = numsSize;
    }
    numsSize = 0;
    left[0] = 0;
    for (int i = 1; i < heightSize; i++) {
        if (numsSize == 0) {
            nums[numsSize] = height[i - 1];
        } else {
            while ((numsSize > 0) && (height[i - 1] > nums[numsSize - 1])) {
                numsSize--;
            }
            nums[numsSize] = height[i - 1];
        }
        numsSize++;
        left[i] = numsSize;
        if ((i + 1) % 2) {
            total += left[i];
        } else {
            total += right[i];
        }
    }
    return total;
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, test001)
{
    int height[6] = {16, 5, 3, 10, 21, 7};
    int res = NumberOfMountainSeen(height, 6);  
    EXPECT_EQ(res, 8);
}