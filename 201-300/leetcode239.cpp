#include <gtest/gtest.h>

struct Heap {
    int **heap;
    int size;
    int capacity;
};

void init(struct Heap* obj, int capacity)
{
    obj->size = 0;
    obj->capacity = capacity;
    obj->heap = (int**)malloc(sizeof(int*) * (obj->capacity + 1));
    for (int i = 1; i <= obj->capacity; i++) {
        obj->heap[i] = (int*)malloc(sizeof(int) * 2);
    }
}

void push(struct Heap* obj, int num0, int num1)
{
    int sub1 = ++(obj->size);
    int sub2 = sub1 >> 1;

    (obj->heap[sub1])[0] = num0;
    (obj->heap[sub1])[0] = num1;
    while (sub2 > 0 && cmp() < 0) {
        
    } 
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    struct Heap* q = (struct Heap*)malloc(sizeof(struct Heap));
    init(q, numsSize);
    for (int i = 0; i < k; i++) {
        push(q, nums[i], i);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num239x001)
{

}