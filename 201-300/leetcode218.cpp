#include <gtest/gtest.h>

struct Heap {
    int capacity;
    int size;
    int *arr;
};

struct Heap* HeapInit(int maxSize)
{
    struct Heap* heap;

    heap = malloc(sizeof(struct Heap));
    heap->capacity = maxSize;
    heap->size = 0;
    heap->arr = malloc(sizeof(int)*(maxSize));

    return heap;
}

void HeapInsert(int x, struct Heap *obj)
{
    obj->arr[obj->size++] = x;
    int i = obj->size - 2;
    while (i >= 0 && obj->arr[i] > obj->arr[i + 1]) {
        int temp = obj->arr[i];
        obj->arr[i] = obj->arr[i + 1];
        obj->arr[i + 1] = temp;
        i--;
    }
}

int HeapGetMax(struct Heap *obj)
{
    if (obj->size > 0) {
        return obj->arr[obj->size - 1];
    } else {
        return 0;
    }
}

void HeapDelete(int x, struct Heap *obj)
{
    for (int i = 0; i < obj->size; i++) {
        if (obj->arr[i] != x) {
            continue;
        }
        while (i < obj->size - 1) {
            obj->arr[i] = obj->arr[i + 1];
            i++;
        }
        obj->size--;
    }
}

int mycmp(const void *a, const void *b)
{
    int x, y;
    int ret = (*((int**)a))[0] - (*((int**)b))[0];
    if (ret == 0) {
        x = -(*((int**)b))[1];
        y = -(*((int**)a))[1];
        return x - y;
    }
    return ret;
}

int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes){
    int **vetex;
    int vetexCount = buildingsSize * 2;

    vetex = (int**)malloc(sizeof(int*) * vetexCount);
    for (int i = 0; i < vetexCount; i++) {
        vetex[i] = (int*)malloc(sizeof(int) * 2);
    }
    for (int i = 0; i < buildingsSize; i++) {
        vetex[2 * i][0] = buildings[i][0];
        vetex[2 * i][1] = -buildings[i][2];
        vetex[2 * i + 1][0] = buildings[i][1];
        vetex[2 * i + 1][1] = buildings[i][2];
    }
    qsort(vetex, vetexCount, sizeof(int*), mycmp);

    struct Heap *heap = HeapInit(buildingsSize);
    *returnSize = 0;
    int lastHeight = 0;
    int **ret = (int**)malloc(sizeof(int*) * vetexCount);
    for (int i = 0; i < vetexCount; i++) {
        if (vetex[i][1] < 0) {
            HeapInsert(-vetex[i][1], heap);
        } else {
            HeapDelete(vetex[i][1], heap);
        }
        if (lastHeight != HeapGetMax(heap)) {
            lastHeight = HeapGetMax(heap);
            ret[*returnSize] = malloc(sizeof(int)*2);
            ret[*returnSize][0] = vetex[i][0];
            ret[*returnSize][1] = HeapGetMax(heap);
            (*returnSize)++;
        }
    }
    *returnColumnSizes = malloc(sizeof(int)*retCount);
    for (i=0; i<retCount; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return ret;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num218x001)
{
    
}