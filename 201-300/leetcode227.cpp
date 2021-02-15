#include <gtest/gtest.h>

int calculate(char * s){
    int len = strlen(s);
    int *stack = (int*)malloc(sizeof(int) * len);
    int top = -1;
    int ans = 0;
    char topOperator = '+';

    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            continue;
        } else if (isdigit(s[i])) {
            int num = 0;
            while (i < len && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            if (topOperator == '-') {
                num *= -1;
            } else if (topOperator == '*') {
                num = num * stack[top--];
            } else if (topOperator == '/') {
                num = stack[top--] / num;
            }
            stack[++top] = num;
        } else {
            topOperator = s[i];
        }
    }
    for (int i = 0; i <= top; i++) {
        ans += stack[i];
    }
    free(stack);
    return ans;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num227x001)
{
    int res = calculate((char*)"3+2*2");
    EXPECT_EQ(res, 7);
}

TEST(LeetCode, num227x002)
{
    int res = calculate((char*)" 3/2 ");
    EXPECT_EQ(res, 1);
}

TEST(LeetCode, num227x003)
{
    int res = calculate((char*)" 3 + 5 / 2 ");
    EXPECT_EQ(res, 5);
}