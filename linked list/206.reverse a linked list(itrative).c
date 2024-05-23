struct ListNode{
    int val;
    struct ListNode *next;
}
struct ListNode* reverseList(struct ListNode* head){
    if(!head) 
        return head;
    struct ListNode *prev = NULL;
    struct ListNode *cur, *next;
    cur = head;
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}