#include <gtest/gtest.h>

#define MAX_SIZE 1024

void dfs(char *s, int index, int len, int leftCount, int rightCount, int leftRemove, int rightRemove, char *path, int pathindex, char **res, int *returnSize)
{
    if (index == len) {
        if (leftRemove == 0 && rightRemove == 0) {
            path[pathindex] = '\0';
            for (int i = 0; i < (*returnSize); i++) {
                if (strcmp(res[i], path) == 0) {
                    return;
                }
            }
            res[(*returnSize)] = (char*)malloc(strlen(path) + 1);
            strcpy(res[(*returnSize)], path);
            (*returnSize)++;
        }
        return;
    }
    if (s[index] == '(' && leftRemove > 0) {
        dfs(s, index + 1, len, leftCount, rightCount, leftRemove - 1, rightRemove, path, pathindex, res, returnSize);
    }
    if (s[index] == ')' && rightRemove > 0) {
        dfs(s, index + 1, len, leftCount, rightCount, leftRemove, rightRemove - 1, path, pathindex, res, returnSize);
    }
    path[pathindex] = s[index];
    if (s[index] != '(' && s[index] != ')') {
        dfs(s, index + 1, len, leftCount, rightCount, leftRemove, rightRemove, path, pathindex + 1, res, returnSize);    
    } else if (s[index] == '(') {
        dfs(s, index + 1, len, leftCount + 1, rightCount, leftRemove, rightRemove, path, pathindex + 1, res, returnSize);
    } else if (rightCount < leftCount) {
        dfs(s, index + 1, len, leftCount, rightCount + 1, leftRemove, rightRemove, path, pathindex + 1, res, returnSize);
    }
}

char ** removeInvalidParentheses(char * s, int* returnSize){
    int len = strlen(s);
    int leftRemove = 0;
    int rightRemove = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            leftRemove++;
        } else if(s[i] == ')') {
            if (leftRemove == 0) {
                rightRemove++;
            }
            if (leftRemove > 0) {
                leftRemove--;
            }
        }
    }
    char *path = (char*)malloc(sizeof(char) * MAX_SIZE);
    char **res = (char**)malloc(sizeof(char*) * MAX_SIZE);
    *returnSize = 0;
    memset(path, 0, sizeof(char) * MAX_SIZE);
    dfs(s, 0, len, 0, 0, leftRemove, rightRemove, path, 0, res, returnSize);
    return res;
}