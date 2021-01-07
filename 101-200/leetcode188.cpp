#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define MAX(a,b) ((a)<(b) ? (b) : (a))

int maxProfit(int k, int* prices, int pricesSize){
    if (pricesSize <= 1 || k < 1) {
        return 0;
    }
    int *k_buy = (int*)malloc(k * sizeof(int));
    int *k_sold = (int*)calloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        k_buy[i] = 0 - prices[0];
    }

    for (int i = 1; i < pricesSize; i++) {
        for (int j = k - 1; j >= 1; j--) {
            k_sold[j] = MAX(k_sold[j], k_buy[j] + prices[i]);
            k_buy[j] = MAX(k_buy[j], k_sold[j-1] - prices[i]);
        }
    }
}