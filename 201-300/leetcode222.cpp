#include <gtest/gtest.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int exists(struct TreeNode *root, int level, int k)
{
    int bits = 1 << (level - 1);
    struct TreeNode *node = root;
    while (node != NULL && bits > 0) {
        if (!(bits & k)) {
            node = node->left;
        } else {
            node = node->right;
        }
        bits >>= 1;
    }
    return node != NULL;
}

int countNodes(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }

    int level = 0;
    struct TreeNode* node = root;
    while (node->left != NULL) {
        level++;
        node = node->left;
    }
    int low = 1 << level;
    int high = (1 << (level + 1)) - 1;
    while (low < high) {
        int mid = (high - low + 1) / 2 + low;
        if (exists(root, level, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num222x001)
{

}