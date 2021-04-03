int rec[502][502];
int val[502];

int solve(int left, int right)
{
    if (left >= right - 1) {
        return 0;
    }
    if (rec[left][right] != -1) {
        return rec[left][right];
    }
    for (int i = left + 1; i < right; i++) {
        int sum = val[left] * val[i] * val[right];
        sum += solve(left, i) + solve(i, right);
        rec[left][right] = fmax(rec[left][right], sum);
    }
    return rec[left][right];
}

int maxCoins(int* nums, int numsSize)
{
    memset(rec, -1, sizeof(rec));
    val[0] = val[numsSize + 1] = 1;
    for (int i = 1; i <= numsSize; i++) {
        val[i] = nums[i - 1];
    }
    return solve(0, numsSize + 1);
}

int maxCoins(int* nums, int numsSize)
{
    int rec[numsSize + 2][numsSize + 2];
    memset(rec, 0, sizeof(rec));
    int val[numsSize + 2];
    val[0] = val[numsSize + 1] = 1;
    for (int i = 1; i <= numsSize; i++) {
        val[i] = nums[i - 1];
    }
    for (int i = numsSize - 1; i >= 0; i--) {
        for (int j = i + 2; j <= numsSize + 1; j++) {
            for (int k = i + 1; k < j; k++) {
                int sum = val[i] * val[k] * val[j];
                sum += rec[i][k] + rec[k][j];
                rec[i][j] = fmax(rec[i][j], sum);
            }        
        }
    }
    return rec[0][numsSize + 1];
}