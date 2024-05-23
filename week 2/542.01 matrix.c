/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MIN(a,b) ((a)<=(b)?(a):(b))

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    for (int i = 0; i < matSize; i++)
    {
        for(int j = 0; j < matColSize[i]; j++)
        {
            if(mat[i][j] > 0)
            {
                int top =(i > 0 ? mat[i-1][j]:INT_MAX);
                //如果目前不是第一行，就取上方元素，如果是第一行，設為INT_MAX-1
                int left = (j > 0 ? mat[i][j-1]:INT_MAX);
                //如果目前不是第一列，就取左方元素，如果是第一列，設為INT_MAX-1
                int temp = (MIN(top,left) == INT_MAX?INT_MAX:MIN(top,left)+1);
                mat[i][j] = temp;
            }
        }
    } //第一次遍歷，從左上到右下，考慮上方和左方元素

    for (int i = matSize-1; i >= 0; i--)
    {
        for(int j = matColSize[i]-1; j >= 0; j--)
        {
            if(mat[i][j] > 0)
            {
                int bottom =(i < matSize-1 ? mat[i+1][j]:INT_MAX);
                //如果目前不是最後一行，就取下方元素，如果是，設為INT_MAX
                int right = (j < matColSize[i]-1 ? mat[i][j+1]:INT_MAX);
                //如果目前不是最後一列，就取右方元素，如果是，設為INT_MAX
                int temp = (MIN(bottom,right) == INT_MAX?INT_MAX:MIN(bottom,right)+1);
                mat[i][j] = MIN(mat[i][j],temp);
                //將當前元素 mat[i][j] 設為當前值和 temp 的較小值。
            }
        }
    } //第二次遍歷，從右下到左上，考慮下方和右方元素
    return mat;
}