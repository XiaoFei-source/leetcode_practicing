/*
definition of a binary tree node.
struct TreeNode{
    int val;
    struct TreeNode *left
    struct TreeNode *right
}*/
bool areTheSame(struct TreeNode *root1, struct TreeNode *root2 )
{
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;   //base case
    //上面不知道要不要包再一起
    return ((root1->val == root2->val) && areTheSame(root1->left, root2->left)
    && areTheSame(root1->right, root2->right)); //check後遞迴，要三者皆成立才為真
}   //check是否一樣的副程式
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    if (!subRoot)
        return true;
    if (!root)
        return false;       //base case
    if (areTheSame(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot)||isSubtree(root->right, subRoot);
    //如果大顆的樹根現在的子樹沒有match，往左邊跟右邊的子樹嘗試
}