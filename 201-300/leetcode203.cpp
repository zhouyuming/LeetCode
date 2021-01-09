
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    struct ListNode* phead = head;
    while (phead != NULL) {
        if  (phead->next && phead->next->val == val) {
            phead->next = phead->next->next;
        } else {
            phead = phead->next;
        }
    }
    return head;
}