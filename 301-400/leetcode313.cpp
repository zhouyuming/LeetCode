int nthSuperUglyNumber(int n, int* primes, int primesSize){
    if (n == 1) {
        return 1;
    }
    int *res = (int *)calloc(n, sizeof(int));
    int rsize = 0;
    int *pids = (int *)calloc(primesSize, sizeof(int));
    res[rsize++] = 1;
    while (rsize < n) {
        int min = INT_MAX;
        int id = 0;
        for (int i = 0; i < primesSize; i++) {
            int tmin = primes[i] * res[pids[i]];
            if (tmin < min) {
                min = tmin;
                id = i;
            } else if (tmin == min) {
                pids[i]++;
            }
        }
        res[rsize++] = min;
        pids[id]++;
    }
    return res[n - 1];
}