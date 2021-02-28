#include <gtest/gtest.h>

#define MAX_SIZE 1000

void backtrack(char* num, int target, char** res, int* returnSize, int index, long val, long mult, char* track)
{
    if (index == strlen(num)) {
        if (val == target) {
            res[*returnSize] = (char*)malloc(sizeof(char) * MAX_SIZE);
            strcpy(res[*returnSize], track);
            (*returnSize)++;
        }
        return;
    }
    int len = strlen(track);
    for (int i = index; i < strlen(num); i++) {
        long n = 0;
        for (int j = index; j <= i; j++) {
            n = n * 10 + (num[j] - '0');
        }
        if (index == 0) {
            strncat(track, &num[index], i - index + 1);
            backtrack(num, target, res, returnSize, i + 1, n, n, track);
            track[len] = 0;
        } else {
            strcat(track, "+");
            strncat(track, &num[index], i - index + 1);
            backtrack(num, target, res, returnSize, i + 1, val + n, n, track);
            track[len] = 0;

            strcat(track, "-");
            strncat(track, &num[index], i - index + 1);
            backtrack(num, target, res, returnSize, i + 1, val - n, -n, track);
            track[len] = 0;

            strcat(track, "*");
            strncat(track, &num[index], i - index + 1);
            backtrack(num, target, res, returnSize, i + 1, val - mult + mult * n, mult * n, track);
            track[len] = 0;
        }
        if (n == 0) return;
    }
}

char ** addOperators(char * num, int target, int* returnSize){
    char** res = (char**)malloc(sizeof(char*) * 4000);
    char* track = (char*)malloc(sizeof(char) * MAX_SIZE);
    memset(track, 0, sizeof(char) * MAX_SIZE);
    *returnSize = 0;
    backtrack(num, target, res, returnSize, 0, 0, 1, track);
    return res;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num282x001)
{

}