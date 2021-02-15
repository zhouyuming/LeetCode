#include <gtest/gtest.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root){
    struct TreeNode* tmp = NULL;

    if (root != NULL) {
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num226x001)
{

}
