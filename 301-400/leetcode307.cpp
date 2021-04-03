int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int *pQueue = (int*)malloc(n * sizeof(int));
    memset(pQueue, 0, n * sizeof(int));
    int front = -1;
    int rear = -1;
    int curr = 1;
    int lenghOfQue = 0;

    if (n == 1 && edgesSize == 0) {
        *returnSize = 1;
        return pQueue;
    }

    int *pIndegree = (int*)malloc(n * sizeof(int));
    memset(pIndegree, 0, n * sizeof(int));

    int** ppGraph = (int**)malloc(n * sizeof(int*));
    int* pColOfGraph = (int*)malloc(n * sizeof(int));
    memset(pColOfGraph, 0, n * sizeof(int));
    int row = 0;
    int col = 0;
    for (row = 0; row <= n - 1; row++) {
        ppGraph[row] = (int*)malloc(n * sizeof(int*));    
    }
    for (row = 0; row <= edgesSize - 1; row++) {
        ppGraph[edges[row][1]][pIndegree[edges[row][1]]++] = edges[row][0];
        ppGraph[edges[row][0]][pIndegree[edges[row][0]]++] = edges[row][1];
        pColOfGraph[edges[row][1]]++;
        pColOfGraph[edges[row][0]]++;
    }

    for (row = 0; row <= n - 1; row++) {
        if (1 == pIndegree[row]) {
            pQueue[++rear] = row;    
        }    
    }

    while (2 < n) {
        lenghOfQue = rear - front;
        n -= lenghOfQue;
        while (lenghOfQue--) {
            curr = pQueue[++front];
            for (col = 0; col <= pColOfGraph[curr] - 1; col++) {
                --pIndegree[curr];
                --pIndegree[ppGraph[curr][col]];
                if (1 == pIndegree[ppGraph[curr][col]]) {
                    pQueue[++rear] = ppGraph[curr][col];    
                }    
            }    
        }   
    }
    *returnSize = rear - front;
    
    return pQueue + front + 1;
}