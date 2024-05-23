#define LEN 0xfffff

typedef struct {
    int *stack1;
    int stack_index1;
    int *stack2;
    int stack_index2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue* )malloc(sizeof(MyQueue));
    obj->stack1 = (int *)malloc(sizeof(int) * LEN);
    obj->stack2 = (int *)malloc(sizeof(int) * LEN);
    obj->stack_index1 = 0;
    obj->stack_index2 = 0;
    
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[obj->stack_index1++] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int ret;
    
    if(!obj->stack_index2) {
        while(obj->stack_index1){
            obj->stack2[obj->stack_index2++] = obj->stack1[--obj->stack_index1];
        }
    }
    
    ret = obj->stack2[--obj->stack_index2];
    return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(!obj->stack_index2) {
        while(obj->stack_index1){
            obj->stack2[obj->stack_index2++] = obj->stack1[--obj->stack_index1];
        }
    }
    
    return obj->stack2[obj->stack_index2-1];  
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(!obj->stack_index1 && !obj->stack_index2) return true;
    return false;
}

void myQueueFree(MyQueue* obj) {
    
}

