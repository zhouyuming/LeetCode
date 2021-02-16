#include <gtest/gtest.h>

#define MaxSize 1000

typedef struct {
    int data1[MaxSize];
    int data2[MaxSize];
    int top1;
    int top2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *simulationQueue = (MyQueue*)malloc(sizeof(MyQueue));
    simulationQueue->top1 = -1;
    simulationQueue->top2 = -1;
    memset(simulationQueue->data1, 0, MaxSize * sizeof(int));
    memset(simulationQueue->data2, 0, MaxSize * sizeof(int));

    return simulationQueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if (obj->top1 == MaxSize - 1) {
        return;
    }
    obj->data1[++obj->top1] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        if (obj->top1 == -1) {
            return NULL;
        }
        while(obj->top1 != -1) {
            obj->data2[++obj->top2] = obj->data1[obj->top1--];
        }
    }
    return obj->data2[obj->top2--];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        if (obj->top1 == -1) {
            return NULL;
        }
        while(obj->top1 != -1) {
            obj->data2[++obj->top2] = obj->data1[obj->top1--];
        }
    }
    return obj->data2[obj->top2];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if (obj->top2 == -1 && obj->top1 == -1) {
        return true;
    } else {
        return false;
    }
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LeetCode, num232x001)
{

}