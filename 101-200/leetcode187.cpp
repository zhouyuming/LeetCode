#include <uthash/include/uthash.h>
#include <gtest/gtest.h>

#define RES_SIZE    100000

char *res[RES_SIZE];

typedef struct _hash_st
{
    char key[11];
    int val;
    UT_hash_handle hh;
} hash_st;

void my_strcpy(char *d, char *s, int len)
{
    for(int i = 0; i < len; i++)
    {
        d[i] = s[i];
    }
    d[len] = '\0';
}

char ** findRepeatedDnaSequences(char * s, int* returnSize){
    int slen = strlen(s);
    if(slen <= 10) {
        *returnSize = 0;
        return NULL;
    }
    hash_st *head = NULL;
    hash_st *pool = (hash_st *)calloc(RES_SIZE, sizeof(hash_st));
    int psize = 0;
    int rsize = 0;
    for(int i = 0; i <= slen - 10; i++) {
        hash_st * cur= &pool[psize];
        my_strcpy(cur->key, &s[i], 10);
        cur->val = 1;
        hash_st *find;
        HASH_FIND_STR(head, cur->key, find);
        if(find == NULL) {
            HASH_ADD_STR(head, key, cur);
            psize++;
            continue;
        }
        if(find->val == 1)
        {
            res[rsize++] = find->key;
        }
        find->val++;
    }
    *returnSize = rsize;
    return res;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num187x001)
{
    int res;
    findRepeatedDnaSequences((char*)"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", &res);
    ASSERT_EQ(res, 2);
}

TEST(LeetCode, num187x002)
{
    int res;
    findRepeatedDnaSequences((char*)"AAAAAAAAAAAAA", &res);
    ASSERT_EQ(res, 1);
}