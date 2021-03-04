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

int mycmp(const void* a, const void* b)
{
    return ((People*)b)->score - ((People*)a)->score;
}

void InitPeoples(int *scores, int scoresSize, int **preference, int *preferenceColSize, People* peoples)
{
    for (int i = 0; i < scoresSize; i++) {
        peoples[i].id = i;
        peoples[i].score = scores[i];
        peoples[i].partNum = preferenceColSize[i];
        peoples[i].partId = (int*)malloc(preferenceColSize[i] * sizeof(int));
        if (peoples[i].partId == NULL) {
            return;
        }
        for (int j = 0; j < preferenceColSize[i]; j++) {
            peoples[i].partId[j] = preference[i][j];
        }
        peoples[i].offer = false;
    }
    return;
}

void FreePeoples(int scoresSize, People* peoples)
{
    if (peoples == NULL) {
        return;
    }
    for (int i = 0; i < scoresSize; i++) {
        if (peoples[i].partId == NULL) {
            free(peoples[i].partId);
            peoples[i].partId = NULL;
        }
    }
    free(peoples);
    peoples = NULL;
    return;
}

int StatisticParts(int numsSize, int* nums)
{
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            total++;
        }
    }
    return total;
}

int StatisticPeoples(int numsSize, People* peoples)
{
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        if (peoples[i].offer != true) {
            total++;
        }
    }
    return total;
}

void FindPeople(People* peoples, int i, int j, int* nums)
{
    for (int k = 0; k < peoples[j].partNum; k++) {
        if (peoples[j].partId[k] == i) {
            if (nums[i] > 0) {
                nums[i]--;
                peoples[j].offer = true;
            }
        }
    }
    return;
}

int *DepartmentRecruit(int *nums, int numsSize, int *scores, int scoresSize, int **preference, int preferenceSize, int *preferenceColSize, int *returnSize)
{
    People* peoples = (People*)malloc(scoresSize * sizeof(People));
    if (peoples == NULL) {
        return NULL;
    }

    InitPeoples(scores, scoresSize, preference, preferenceColSize, peoples);
    qsort(peoples, scoresSize, sizeof(People), mycmp);
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < scoresSize; j++) {
            if (peoples[j].offer) {
                continue;
            }
            FindPeople(peoples, i, j, nums);
        }
    }
    *returnSize = 2;
    int* res = (int*)malloc((*returnSize) * sizeof(int));
    if (res == NULL) {
        FreePeoples(scoresSize, peoples);
        return NULL;
    }
    res[0] = StatisticParts(numsSize, nums);
    res[1] = StatisticPeoples(scoresSize, peoples);
    FreePeoples(scoresSize, peoples);
    return res;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, test001)
{
    int nums[3] = {0, 1, 0};
    int scores[3] = {65, 65, 80};

    int** preference = (int**)malloc(sizeof(int*) * 3);
    preference[0] = (int*)malloc(sizeof(int) * 3);
    preference[0][0] = 0;
    preference[0][1] = 1;
    preference[0][2] = 2;

    preference[1] = (int*)malloc(sizeof(int) * 2);
    preference[1][0] = 0;
    preference[1][1] = 1;

    preference[2] = (int*)malloc(sizeof(int));
    preference[2][0] = 0;

    int* preferenceColSize = (int*)malloc(sizeof(int) * 3);
    preferenceColSize[0] = 3;
    preferenceColSize[1] = 2;
    preferenceColSize[2] = 1;

    int returnSize = 0;

    int* res = DepartmentRecruit(nums, 3, scores, 3, preference, 3, preferenceColSize, &returnSize);
    EXPECT_EQ(res[0], 0);
    EXPECT_EQ(res[1], 2);
}