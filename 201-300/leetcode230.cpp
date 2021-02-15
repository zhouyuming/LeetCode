#include <gtest/gtest.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*int numofRoot(struct TreeNode* root)
{
    if (!root) {
        return 0;
    }
    return 1 + numofRoot(root->left) + numofRoot(root->right);
}

int kthSmallest(struct TreeNode* root, int k){
    int cnt = numofRoot(root->left);

    if (k <= cnt) {
        return kthSmallest(root->left, k);
    } else if (k > cnt + 1) {
        return kthSmallest(root->right, k - cnt - 1);
    }
    return root->val;
}*/

void dfs(struct TreeNode* root, int k, int* cnt, int*res)
{
    if (root == NULL) {
        return;
    }

    dfs(root->left, k, cnt, res);
    (*cnt)++;
    if (*cnt == k) {
        *res = root->val;
    }
    dfs(root->right, k, cnt, res);
}

int kthSmallest(struct TreeNode* root, int k){
    int res = 0;
    int cnt = 0;
    dfs(root, k, &cnt, &res);
    return res;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num230x001)
{

}