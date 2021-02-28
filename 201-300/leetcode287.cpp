int findDuplicate(int* nums, int numsSize){
    int rear = 0, front = 0;
    do {
        rear = nums[rear];
        front = nums[nums[front]];
    } while (rear != front);//存在圈，第一相遇点

    rear = 0;
    while (rear != front) {
        rear = nums[rear];
        front = nums[front];
    }                       //重跑，第二相遇点即为分支点
    return rear;
}