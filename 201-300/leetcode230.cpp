#include <gtest/gtest.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int numofRoot(struct TreeNode* root)
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
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num230x001)
{

}