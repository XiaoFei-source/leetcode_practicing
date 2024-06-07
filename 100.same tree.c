/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*想法:每個點有三種可能
1.其中一點為空，則樹必然不同，return false
2.2點皆為空，return tree
3.2點皆有值，看值是否相同，接著check左子樹、右子樹*/
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if((p && !q)||(!p && q))
        return false;
    if(!p && !q)
        return true;
    return((p->val == q->val) && isSameTree(p->left, q->left) 
    && isSameTree(p->right, q->right));
}