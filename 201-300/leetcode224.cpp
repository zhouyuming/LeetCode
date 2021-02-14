#include <gtest/gtest.h>

int calculate(char * s){
    int temp = 0;
    int len = strlen(s);
    int answer = 0;
    int * stack = (int *)calloc(len,sizeof(int));
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            temp = temp * 10 + (int)(s[i] - '0');
        }
        if (s[i] == '+') {
            answer += sign * temp;
            sign = 1;
            temp = 0;
        } else if (s[i] == '-') {
            answer += sign * temp;
            sign = -1;
            temp = 0;
        } else if(s[i] == '(') {
            stack[++top] = answer;      //先将之前的计算结果压栈
            stack[++top] = sign;        //将括号前的符号标记压栈，整个表达式计算完成时 ，乘以该标记位确定结果符号
            sign = 1;           //标记位初始化位1
            answer = 0;     //计算结果清零
        } else if(s[i] == ')') {
            answer += sign * temp;      //计算右括号前面的数字，将结果存入结果变量
            answer *= stack[top--];         //确定整个表达式的符号
            answer += stack[top--];     //累加之前计算的结果
            temp = 0;       //临时变量清零
        }
    }
    answer += sign * temp;
    free(stack);
    return answer;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num224x001)
{

}