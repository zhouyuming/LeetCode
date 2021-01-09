#include <gtest/gtest.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* phead = head;
    struct ListNode* temp1 = NULL;
    struct ListNode* temp2 = NULL;
    if (head == NULL) {
        return NULL;
    }
    temp1 = phead->next;
    while (temp1) {
        temp2 = temp1->next;
        temp1->next = phead;
        phead = temp1;
        temp1 = temp2;
    }
    head->next = NULL;
    return phead;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}