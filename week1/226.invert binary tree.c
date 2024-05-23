// Definition for a binary tree node.
// struct TreeNode{
//    int val;
//   struct TreeNode *left;
//    struct TreeNode *right;
// }

struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL)
    {
        return NULL;
    }
    struct TreeNode *temp_root;
    temp_root = root->left;
    root->left = root->right;
    root->right = temp_root;
    invertTree(root->left);
    invertTree(root->right);
    return root;

}