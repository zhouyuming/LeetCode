
int mycmp(const void* a, const void* b)
{
    char s1[100];
    char s2[100];
    sprintf(s1, "%d%d", *(int*)a, *(int*)b);
    sprintf(s2, "%d%d", *(int*)b, *(int*)a);
    return strcmp(s2, s1);
}

char * largestNumber(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), mycmp);
    if (nums[0] == 0) {
        return 0;
    }
    char* result = NULL;
    char* p = NULL;
    result = malloc(sizeof(char) * 1000);
    p = result;
    for (int i = 0; i < numsSize; i++) {
        sprintf(p, "%d", nums[i]);
        p += strlen(p);
    }
    return result;
}