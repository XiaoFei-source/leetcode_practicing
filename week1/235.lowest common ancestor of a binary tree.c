//目標:給定兩節點，找到最低共同祖先
//Definition of a binary tree
//struct TreeNode{
//    int val;
//    struct TreeNode *left;
//    struct TreeNode *right;
//}
struct TreeNode* lowestcommonAncestor(struct TreeNode *root,struct TreeNode *p,struct TreeNode *q){
    //如果root大於p跟q，則p,q都一定在root的左邊
    //將root 往左邊向下移動
    if(root->val > p->val && root->val > q->val) 
    {
        return lowestCommonAncestor(root->left,p,q);
    }    
    //如果root小於p跟q，則p,q都一定在root的右邊
    //將root 往右邊向下移動
    else if(root->val < p->val && root->val < q->val) 
    {
        return lowestCommonAncestor(root->right,p,q);
    }
    //如果以上兩種情況都不滿足，則表示p和q分別位於root的左右子樹中，
    //此時root就是最低共同祖先。
    return root;
}

//優化解，別人的(基本上一樣)
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;
}