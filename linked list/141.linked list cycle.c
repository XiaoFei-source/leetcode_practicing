typedef struct ListNode Node;
bool hasCycle(struct ListNode *head) {
    Node *slow = head;
    Node *fast = head;

    while(slow&&fast&&(fast->next)){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;       
    } 
    return false;
}
//static inline Node *move(Node *cur){return cur?cur->next:NULL;}
// bool hasCycle(struct ListNode *head) {
//     //struct ListNode **tail;
//     int *length,int *mu,int *lambda;
//     Node *slow = move(head);
//     Node *fast = move(move(head));

//     while(slow&&fast){
//         slow = move(slow);
//         fast = move(move(fast));
//     }    

//     if(!fast){
//         *tail = NULL;
//         *length = 0;
//         slow = head;
//         while(slow&&slow = move(slow));
//             (*length)++;
//         return false;
//     }

//     *mu = 0;
//     slow = head;
//     while(slow!= fast){
//         *(mu)++;
//         slow = slow->next;
//         fast = fast->next->next;
//     }

    // *lambda = 1;
    // slow = move(slow);
    // *tail = slow;
    // while (slow != fast){
    //     *tail =slow;
    //     (*lambda)++;
    //     slow = move(slow);
    // }
    // *length = *mu + *lambda;

    // return true;

}