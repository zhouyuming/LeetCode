int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int missingNumber(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int i;
    /* 排序后[0,n], 与下标对不上的就是缺失的元素 */
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != i) {
            return i;
        }
    }
    return numsSize;
}
