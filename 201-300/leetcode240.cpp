#include <gtest/gtest.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i = matrixSize - 1, j = 0;
    while (i >= 0 && j < matrixColSize[0]) {
        if (target < matrix[i][j]) i--;
        else if (target > matrix[i][j]) j++;
        else return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num240x001)
{

}