/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//想法:DFS，起始数据点开始，查看周围相邻的四个点（上下左右），
//看这四个点的颜色是否为所要改的颜色，
//若是，则把该点颜色改为新颜色并以该点为新起点继续查找周围相邻的四点，以此类推，
//直到查到边界或者点的颜色值不等于所要更改的颜色时
//，return上一个点，继续完成上一个点的其他方向的查找。
#define ROW 50
#define COL 50

int color1,color2;
int a_limit,b_limit;
int **floodFill(int **image,int imageSize ,int *imageColSize, int sr, int sc,
        int color, int *returnSize, int **returnColumnSizes)
/*輸入參數:一圖像陣列，起始位置[sr][sc]，新顏色color，返回填充後的圖像陣列(2維陣列)*/
{
    int **dynArr2D = (int**)malloc(sizeof(int*)*ROW);

    for(int i = 0; i < ROW; i++){
        dynArr2D[i] = (int*)malloc(sizeof(int)*COL);
    } //動態分配2維陣列
    color1 = image[sr][sc]; //起始格的顏色
    color2 = color; //要填充的新顏色

    a_limit = imageSize;
    b_limit = imageColSize[0];
    
    for (int i = 0; i < a_limit; i++){
        for (int j = 0; j < b_limit; j++){
            dynArr2D[i][j] = image[i][j];
        } //將原圖像 image 的內容複製到 dynArr2D
    }
    if(color1 != color2){
        do_fill(sr, sc, dynArr2D);
    } //color1 和 color2 不同，則從起始位置開始進行填充
    *returnColumnSizes = imageColSize;
    *returnSize = imageSize; //設定返回的圖像大小和列大小
    return dynArr2D;  //返回填充後的圖像 dynArr2D
}
/*do_fill函式進行遞迴，若當前顏色不是color1則返回，否則將設為color2
並且檢查並填充四個方向*/
void do_fill(int a, int b, int **img){
    if (img[a][b] != color1){
        return;
    }
    img[a][b] = color2;

    if (check_a_range(a+1)){   /*向下塗滿*/
        do_fill(a+1, b, img);
    }
    if (check_a_range(a-1)){    /*向上塗滿*/
        do_fill(a-1, b, img);
    }
    if (check_b_range(b+1)){    /*向右塗滿*/
        do_fill(a, b+1, img);
    }
    if (check_b_range(b-1)){    /*向左塗滿*/
        do_fill(a, b-1, img);
    }
}
//檢查新位置[a][b]是否超出邊界
int check_a_range(int a)
{
    if((a < a_limit) && (a >= 0)){
        return 1;
    } else{
        return 0;
    } 
}

int check_b_range(int b)
{
    if((b < b_limit) && (b >= 0)){
        return 1;
    } else{
        return 0;
    } 
}