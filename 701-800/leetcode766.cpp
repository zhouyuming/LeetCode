#include <gtest/gtest.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){
    for (int i = 0; i < matrixColSize[0]; i++) {
        int row = 0;
        int col = i;
        int value = matrix[row][col];
        while (row < matrixSize && col < matrixColSize[0]) {
            if (matrix[row][col] != value) {
                return false;
            }
            row++;
            col++;
        }
    }

    for (int i = 1; i < matrixSize; i++) {
        int row = i;
        int col = 0;
        int value = matrix[row][col];
        while (row < matrixSize && col < matrixColSize[0]) {
            if (matrix[row][col] != value) {
                return false;
            }
            row++;
            col++;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num766x001)
{

}