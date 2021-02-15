#include <gtest/gtest.h>

#define LEN 20

typedef struct queue {
    int *data;
    int head;
    int rear;
    int size;
} Queue;

typedef struct {
    Queue *queue1, *queue2;s
} MyStack;

Queue *initQueue(int k) {
    Queue *obj = (Queue *)malloc(sizeof(Queue));
    obj->data = (int *)malloc(k * sizeof(int));
    obj->head = -1;
    obj->rear = -1;
    obj->size = k;
    return obj;
}

void enQueue(Queue *obj, int e) {
    if (obj->head == -1) {
        obj->head = 0;
    }
    obj->rear = (obj->rear + 1) % obj->size;
    obj->data[obj->rear] = e;
}

int deQueue(Queue *obj) {
    int a = obj->data[obj->head];
    if (obj->head == obj->rear) {
        obj->rear = -1;
        obj->head = -1;
        return a;
    }
    obj->head = (obj->head + 1) % obj->size;
    return a;
}

int isEmpty(Queue *obj) {
    return obj->head == -1;
}

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->queue1 = initQueue(LEN);
    obj->queue2 = initQueue(LEN);
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {

}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {

}

/** Get the top element. */
int myStackTop(MyStack* obj) {

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {

}

void myStackFree(MyStack* obj) {

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num225x001)
{

}
