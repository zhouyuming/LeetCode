int CmpFun(const void* a, const void* b)
{
    return *((int*)b) - *((int*)a);
}

int hIndex(int* citations, int citationsSize){
    if (citations == NULL || citationsSize <= 0) {
        return 0;
    }
    qsort(citations, citationsSize, sizeof(int), CmpFun);
    int h;
    for (h = 0; h < citationsSize; h++) {
        if (citations[h] <= h) {
            break;
        }
    }
    return h;
}