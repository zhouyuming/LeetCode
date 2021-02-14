#include <gtest/gtest.h>

/*int getf(int* f, int x)
{
    if (f[x] == x) {
        return x;
    }
    int newf = getf(f, f[x]);
    f[x] = newf;
    return newf;
}

void add(int *f, int x, int y)
{
    int fx = getf(f, x);
    int fy = getf(f, y);
    f[fx] = fy;
}

int minSwapsCouples(int* row, int rowSize){
    int n = rowSize;
    int tot = n / 2;
    int f[tot];

    memset(f, 0, sizeof(f));
    for (int i = 1; i < tot; i++) {
        f[i] = i;
    }

    for (int i = 0; i < n; i += 2) {
        int l = row[i] / 2;
        int r = row[i + 1] / 2;
        add(f, l, r);
    }

    int m[tot];
    memset(m, 0, sizeof(m));
    for (int i = 0; i < tot; i++) {
        int fx = getf(f, i);
        m[fx]++;
    }
    int ret = 0;
    for (int i = 0; i < tot; i++) {
        if (f[i] == i) {
            ret += m[i] - 1;
        }
    }
    return ret;
}*/

int minSwapsCouples(int* row, int rowSize) 
{
    int n = rowSize;
    int tot = n / 2;

    int* graph[tot];
    int graphColSize[tot];
    memset(graphColSize, 0, sizeof(graphColSize));
    for (int i = 0; i < n; i += 2) {
        int l = row[i] / 2;
        int r = row[i + 1] / 2;
        if (l != r) {
            graphColSize[l]++;
            graphColSize[r]++;
        }
    }

    for (int i = 0; i < tot; i++) {
        graph[i] = (int*)malloc(sizeof(int) * graphColSize[i]);
        graphColSize[i] = 0;
    }

    for (int i = 0; i < n; i += 2) {
        int l = row[i] / 2;
        int r = row[i + 1] / 2;
        if (l != r) {
            graph[l][graphColSize[l]++] = r;
            graph[r][graphColSize[r]++] = l;
        }
    }
    int visited[tot];
    memset(visited, 0, sizeof(visited));
    int que[n];
    int ret = 0;
    for (int i = 0; i < tot; i++) {
        if (visited[i] == 0) {
            int left = 0, right = 0;
            visited[i] = 1;
            que[right++] = i;
            int cnt = 0;
            
            while (left < right) {
                int x = que[left++];
                cnt += 1;
                for (int j = 0; j < graphColSize[x]; j++) {
                    if (visited[graph[x][j]] == 0) {
                        visited[graph[x][j]] = 1;
                        que[right++] = graph[x][j];
                    }
                }
            }
            ret += cnt - 1;
        }
    }
    return ret;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num765x001)
{
    int nums[4] = {0, 2, 1, 3};
    int res = minSwapsCouples(nums, 4);
    EXPECT_EQ(res, 1);
}

TEST(LeetCode, num765x002)
{
    int nums[4] = {3, 2, 0, 1};
    int res = minSwapsCouples(nums, 4);
    EXPECT_EQ(res, 0);
}