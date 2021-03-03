/*
第一题部门招聘
nums代表每个部门要招聘的人数，部门ID为数组下标
scores代表每个应聘者的分数，用户ID未数组下标
preference代表每个应聘者的意向部门（存的部门ID），每个应聘者有1-3个意向部门
部门ID越小录取优先权越高，部门会录用分数最高者且对该部门有意向者，分数相同时，录用ID最小的人。
每个人只能被一个部门录取一次。
返回未达成招聘指标的部门数量和未找到工作的数量，即长度为2的数组
例如
nums = [0, 1, 0]
scores = [65, 65, 80]
preference = [[0, 1, 2],  [0, 1], [0]]
返回[0, 2]。 id为1的应聘者被1号部门录取。每个部门都完成了招聘指标

思路：设计应聘者结构体，存在信息，然后按照分数从高到低排列，部门从0号开始筛选应聘者，对部门有意向的应聘者进行录取，成功录取后标记位已录用。
*/

#include <gtest/gtest.h>

typedef struct {
    int id;
    int score;
    int partNum;
    int* partId;
    bool offer;
} People;

int *DepartmentRecruit(int *nums, int numsSize, int *scores, int scoresSize, int **preference, int preferenceSize, int *preferenceColSize, int *returnSize)
{

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, test001)
{

}