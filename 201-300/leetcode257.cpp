#include <gtest/gtest.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_LEN 200
#define RET_LEN 100

void dfs(struct TreeNode* root, char* s, int len, char** res, int* returnSize)
{
    int ll = sprintf(s + len, "->%d", root->val);
    if (root->left == NULL && root->right == NULL) {
        s[len + ll] = '\0';
        res[(*returnSize)] = (char*)malloc(MAX_LEN);
        strcpy(res[(*returnSize)++], s);
        return;
    }
    if (root->left) {
        dfs(root->left, s, len + ll, res, returnSize);
    }
    if (root->right) {
        dfs(root->right, s, len + ll, res, returnSize);
    }
    return;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    char* pathStr = (char*)malloc(sizeof(char) * MAX_LEN);
    char** res = (char**)malloc(sizeof(char*) * RET_LEN);
    int len = sprintf(pathStr, "%d", root->val);
    if (root->left == NULL && root->right == NULL) {
        pathStr[len] = '\0';
        res[(*returnSize)] = (char*)malloc(MAX_LEN);
        strcpy(res[(*returnSize)++], pathStr);
        return res;
    }
    if (root->left) {
        dfs(root->left, pathStr, len, res, returnSize);
    }
    if (root->right) {
        dfs(root->right, pathStr, len, res, returnSize);
    }
    return res;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num257x001)
{

}