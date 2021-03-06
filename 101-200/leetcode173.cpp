#include <gtest/gtest.h>

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

typedef struct {
    struct TreeNode* stack[256];
    int top;
} BSTIterator;

struct TreeNode* root = NULL;
BSTIterator* obj = NULL;

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj->top = 0;
    while (root) {
        obj->stack[obj->top++] = root;
        root = root->left;
    }
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* root = obj->stack[--obj->top];
    int val = root->val;
    root = root->right;
    while (root) {
        obj->stack[obj->top++] = root;
        root = root->left;
    }
    return val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top > 0;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj);
}

class FooEnvironment : public testing::Environment
{
public:
    virtual void SetUp()
    {
        
    }
    virtual void TearDown()
    {
    }
};

class LeetCodeTest : public testing::Test {
 protected:
  static void SetUpTestCase() {
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    memset(root, 0, sizeof(struct TreeNode));
    root->val = 7;
    struct TreeNode* tmp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    memset(tmp, 0, sizeof(struct TreeNode));
    tmp->val = 3;
    root->left = tmp;
    struct TreeNode* tmp1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    memset(tmp1, 0, sizeof(struct TreeNode));
    tmp1->val = 15;
    root->right = tmp1;
    struct TreeNode* tmp2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    memset(tmp2, 0, sizeof(struct TreeNode));
    tmp2->val = 9;
    tmp1->left = tmp2;
    struct TreeNode* tmp3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    memset(tmp3, 0, sizeof(struct TreeNode));
    tmp3->val = 20;
    tmp1->right = tmp3;
    obj = bSTIteratorCreate(root);
  }
  static void TearDownTestCase() {
    bSTIteratorFree(obj);
  }
};

int main(int argc, char **argv)
{
    ::testing::AddGlobalTestEnvironment(new FooEnvironment);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST_F(LeetCodeTest, num173x001)
{
    int res = bSTIteratorNext(obj);
    
    ASSERT_EQ(res, 3);
}

TEST_F(LeetCodeTest, num173x002)
{
    int res = bSTIteratorNext(obj);
    
    ASSERT_EQ(res, 7);
}

TEST_F(LeetCodeTest, num173x003)
{
    bool res = bSTIteratorHasNext(obj);
    
    ASSERT_EQ(res, true);
}

TEST_F(LeetCodeTest, num173x004)
{
    int res = bSTIteratorNext(obj);
    
    ASSERT_EQ(res, 9);
}

TEST_F(LeetCodeTest, num173x005)
{
    bool res = bSTIteratorHasNext(obj);
    
    ASSERT_EQ(res, true);
}

TEST_F(LeetCodeTest, num173x006)
{
    int res = bSTIteratorNext(obj);
    
    ASSERT_EQ(res, 15);
}

TEST_F(LeetCodeTest, num173x007)
{
    bool res = bSTIteratorHasNext(obj);
    
    ASSERT_EQ(res, true);
}

TEST_F(LeetCodeTest, num173x008)
{
    int res = bSTIteratorNext(obj);
    
    ASSERT_EQ(res, 20);
}

TEST_F(LeetCodeTest, num173x009)
{
    bool res = bSTIteratorHasNext(obj);
    
    ASSERT_EQ(res, false);
}