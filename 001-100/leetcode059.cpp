int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **res = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        res[i] = (int*)malloc(sizeof(int) * n);
        memset(res[i], 0, sizeof(int) * n);
    }

    int len = (n + 1) / 2;
    int value = 1;
    for (int i = 0; i < len; i++) {
        int j;
        for (j = i; j < n - i; j++) {
            res[i][j] = value;
            value++;
        }
        if (j - i == 1) {
            break;
        }
        for (j = i + 1; j < n - i - 1; j++) {
            res[j][n - i - 1] = value;
            value++;
        }
        for (j = n - i - 1; j >= i; j--) {
            res[n - i - 1][j] = value;
            value++;
        }
        for (j = n - i - 2; j >= i + 1; j--) {
            res[j][i] = value;
            value++;
        }
    }
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return res;
}