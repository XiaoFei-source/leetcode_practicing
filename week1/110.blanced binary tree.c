//balanced binary tree:樹的每個節點的左右子樹的高度差都不超過一
//Definition of a binary tree
//struct TreeNode{
//    int val;
//    struct TreeNode *left;
//    struct TreeNode *right;
//解法一:
//重複遍歷節點，每到一個節點就將左右子樹深度計算出來，然後判斷是否符合條件
int TreeDepth(struct TreeNode *root)
//用於計算一個二元樹的深度
{
    if(root==NULL)
        return 0;
    int left = TreeDepth(root->left);
    int right = TreeDepth(root->right);
    return(left>right)?left+1:right+1;
    //每個節點的深度是其左右子樹深度的最大值加一，因為它本身也算一層。
}
bool isBalanced(struct TreeNode *root){
    //檢查一棵二元樹是否是平衡的
    if(root==NULL)
        return true;
    //當樹是空的時候，它也被視為是平衡的
    int left = TreeDepth(root->left);
    int right = TreeDepth(root->right);
    int dif = abs(left-right);
    if (dif > 1)
        return false;
    return isBalanced(root->left)&&isBalanced(root->right)
    //透過遞迴，計算其左右子樹的深度，並計算其深度差。如果任何節點的深度差超過1
    //則返回 false，否則繼續遞迴檢查其左右子樹。
}

//解法二:
//每個節點遍歷一遍....待補完
//採用後續遍歷(postorder)，適合在需要從底部開始
//計算或判斷的情況下使用，比如計算樹的高度或檢查平衡性。
bool Balanced(struct TreeNode *root,int *pdepth)
{
    //若為空樹，直接返回
    if(root==NULL){
        *pdepth = 0;
        return true;
    }
    //紀錄左右節點深度
    int left, right;
    //用後續遍歷(postorder)，先做左邊
    if(Balanced(root->left,&left) && Balanced(root->right,&right)){
        //判斷左右子樹是否滿足條件 
        int dif = abs(left - right);        
        if (dif<=1){
            //若滿足條件就讓自身加上子樹的深度，
            //遞迴到上一層時，left、right就是左右子樹的高度
            *pdepth = 1 + (left > right?left:right);
            //比較左右哪棵高，當前節點的高度就為較高的再+1
            return true;
        }
    }
    return false;
}
bool isBalanced(struct TreeNode *root){
    int pdepth = 0;
    return Balanced(root,&pdepth);
}
