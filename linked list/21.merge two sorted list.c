struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *ptr = head;
    while(list1&&list2){
        if(list1->val<list2->val){
            ptr->next=list1;
            list1=list1->next;
        }
        else{
            ptr->next=list2;
            list2=list2->next;
        }
        ptr=ptr->next;
    }
    ptr->next=list1?list1:list2;
    return head->next;
}