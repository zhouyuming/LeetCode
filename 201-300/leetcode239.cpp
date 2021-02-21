#include <gtest/gtest.h>

/*struct Heap {
    int **heap;
    int size;
    int capacity;
};

int cmp(int* a, int* b)
{
    return a[0] == b[0] ? a[1] - b[1] : a[0] - b[0];
}

void swap(int** a, innnt )
{
    int* temp = *a;
    *a = *b;
    *b = temp;
}

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
    while (sub2 > 0 && cmp(obj->heap[sub2], obj->heap[sub1]) < 0) {
        swap(&(obj->heap[sub1]), &(obj->heap[sub2]));
        sub1 = sub2;
        sub2 = sub1 >> 1;   
    } 
}

void pop(struct Heap* obj)
{
    int sub = 1;
    swap(&(obj->heap[sub]), &(obj->heap[(obj->size)--]));
    while (sub <= obj->size) {
        int sub1 = sub << 1;
        int sub2 = sub << 1 | 1;
        int maxSub = sub;
        if (sub1 <= obj->size && cmp(obj->heap[maxSub], ob->heap[sub1])) {
            maxSub = sub1;
        }
        if (sub2 <= obj->size && cmp(obj->heap[maxSub], ob->heap[sub2])) {
            maxSub = sub2;
        }
        if (sub == maxSub) {
            break;
        }
        swap(&(obj->heap[sub]), &(obj->heap[maxSub]));
        sub = maxSub;
    }
}

int* top(struct Heap* obj)
{
    return obj->heap[1];
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    struct Heap* q = (struct Heap*)malloc(sizeof(struct Heap));
    init(q, numsSize);
    for (int i = 0; i < k; i++) {
        push(q, nums[i], i);
    }
    int* ans = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = 0;
    ans[(*returnSize)++] = top(q)[0];
    for (int i = k; i < numsSize; i++) {
        push(q, nums[i], i);
        while (top(q)[1] <= i - k) {
            pop(q);
        }
        ans[(*returnSize)++] = top(q)[0];
    }
}*/

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int q[numsSize];
    int left = 0;
    int right = 0;
    for (int i = 0; i < k; i++) {
        while (left < right && nums[i] >= nums[q[right - 1]]) {
            right--;
        }
        q[right++] = i;
    }
    *returnSize = 0;
    int* ans = malloc(sizeof(int) * (numsSize - k + 1));
    ans[(*returnSize)++] = nums[q[left]];
    for (int i = k; i < numsSize; i++) {
        while (left < right && nums[i] >= nums[q[right - 1]]) {
            right--;
        }
        q[right++] = i;
        while (q[left] <= i - k) {
            left++;
        }
        ans[(*returnSize)++] = nums[q[left]];
    }
    return ans;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num239x001)
{

}