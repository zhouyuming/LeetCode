#include <gtest/gtest.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX 20000

int depth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    int leftH = depth(root->left);
    int rightH = depth(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

int* rightSideView(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    int dep = depth(root);
    int *res = (int*)malloc(sizeof(int) * dep);

    struct TreeNode *queue[MAX];
    int head = 0;
    int tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        int size = tail - head;
        for (int i = 0; i < size; i++) {
            struct TreeNode* tmp = queue[head++];
            if (i == 0) res[(*returnSize)] = tmp->val;
            if (tmp->right) {
                queue[tail++] = tmp->right;
            }
            if (tmp->left) {
                queue[tail++] = tmp->left;
            }
        }
        (*returnSize)++;
    }
    return res;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

