#include <gtest/gtest.h>

/*int **edges;
int *edgeColSize;
int *visited;
int *result;
int resultSize;
bool valid;

void dfs(int u)
{
    visited[u] = 1;
    for (int i = 0; i < edgeColSize[u]; i++) {
        if (visited[edges[u][i]] == 0) {
            dfs(edges[u][i]);
            if (!valid) {
                return;
            }
        } else if (visited[edges[u][i]] == 1) {
            valid = false;
            return;
        }
    }
    visited[u] = 2;
    result[resultSize++] = u;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    valid = true;
    edges = (int**)malloc(sizeof(int*) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        edges[i] = (int*)malloc(0);
    }
    edgeColSize = (int*)malloc(sizeof(int) * numCourses);
    memset(edgeColSize, 0, sizeof(int) * numCourses);
    visited = (int*)malloc(sizeof(int) * numCourses);
    memset(visited, 0, sizeof(int) * numCourses);
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][1];
        int b = prerequisites[i][0];
        edgeColSize[a]++;
        edges[a] = (int*)realloc(edges[a], sizeof(int) * edgeColSize[a]);
        edges[a][edgeColSize[a] - 1] = b;
    }
    result = (int*)malloc(sizeof(int) * numCourses);
    resultSize = 0;
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < numCourses; i++) {
        free(edges[i]);
    }
    free(edges);
    free(edgeColSize);
    free(visited);
    if (!valid) {
        *resultSize = 0;
    } else {
        *returnSize = numCourses;
    }
    for (int i = 0; i < numCourses / 2; i++) {
        int t = nums[i];
        result[i] = result[numCourses - i - 1];
        result[numCourses - i - 1] = t;
    }
    return result;
}*/

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    int** edges = (int**)malloc(sizeof(int*) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        edges[i] = (int*)malloc(0);
    }
    int edgeColSize[numCourses];
    memset(edgeColSize, 0, sizeof(edgeColSize));
    int indeg[numCourses];
    memset(indeg, 0, sizeof(indeg));
    for (int i = 0; i < prerequisitesSize; ++i) {
        int a = prerequisites[i][1], b = prerequisites[i][0];
        edgeColSize[a]++;
        edges[a] = (int*)realloc(edges[a], sizeof(int) * edgeColSize[a]);
        edges[a][edgeColSize[a] - 1] = b;
        ++indeg[b];
    }
    int q[numCourses];
    int l = 0, r = -1;
    for (int i = 0; i < numCourses; ++i) {
        if (indeg[i] == 0) {
            q[++r] = i;
        }
    }

    int* result = (int*)malloc(sizeof(int) * numCourses);
    int resultSize = 0;

    int visited = 0;
    while (l <= r) {
        ++visited;
        int u = q[l++];
        result[resultSize++] = u;
        for (int i = 0; i < edgeColSize[u]; ++i) {
            --indeg[edges[u][i]];
            if (indeg[edges[u][i]] == 0) {
                q[++r] = edges[u][i];
            }
        }
    }
    for (int i = 0; i < numCourses; i++) {
        free(edges[i]);
    }
    free(edges);
    if (visited == numCourses) {
        *returnSize = numCourses;
    } else {
        *returnSize = 0;
    }
    return result;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num210x001)
{
    int res;
    
    EXPECT_EQ(res, 2);
}