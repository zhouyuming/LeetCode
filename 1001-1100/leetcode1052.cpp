#include <gtest/gtest.h>

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X){
    int total = 0;
    int n = customersSize;
    for (int i = 0; i < n; i++) {
        if (grumpy[i] == 0) {
            total += customers[i];
        }
    }

    int increase = 0;
    for (int i = 0; i < X; i++) {
        increase += customers[i] * grumpy[i];
    }
    int maxIncrease = increase;
    for (int i = X; i < n; i++) {
        increase = increase - customers[i - X] * grumpy[i - X] + customers[i] * grumpy[i];
        maxIncrease = fmax(maxIncrease, increase);
    }
    return total + maxIncrease;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num1052x001)
{

}