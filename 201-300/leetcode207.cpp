#include <gtest/gtest.h>

bool dfs(int v, int** g, int* gnums, int* visit)
{
    if (gnums[v] == 0) {
        return true;
    }

    if (visit[v] == -1) {
        return true;
    }

    if (visit[v] == 1) {
        return false;
    }

    visit[v] = 1;
    
    bool res = true;
    for (int i = 0; i < gnums[v]; i++) {
        res = dfs(g[v][i], g, gnums, visit);
        if (res == false) {
            break;
        }
    }
    visit[v] = -1;
    return res;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int* visit = (int*)malloc(sizeof(int) * numCourses);
    int** g = (int**)malloc(sizeof(int*) * numCourses);
    int* gnums = (int*)malloc(sizeof(int) * numCourses);
    memset(visit, 0, sizeof(int) * numCourses);
    memset(gnums, 0, sizeof(int) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        g[i] = (int*)malloc(sizeof(int) * numCourses);
        memset(g[i], 0, sizeof(int) * numCourses);
    }
    for (int i = 0; i < prerequisitesSize; i++) {
        g[prerequisites[i][0]][gnums[prerequisites[i][0]]++] = prerequisites[i][1]; 
    }
    bool res = true;
    for (int i = 0; i < numCourses; i++) {
        for (int j = 0; j < gnums[i]; j++) {
            res = dfs(g[i][j], g, gnums, visit);
            if (res == false) {
                return res;
            }
        }
    }
    return res;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
