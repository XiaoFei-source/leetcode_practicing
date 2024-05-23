//  題目描述:
//  Return an array of arrays of size *returnSize.
//  The sizes of the arrays are returned as *returnColumnSizes array.
//  Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
int cmp(const void *pa, const void *pb){
    const int* a = *(const int**)pa;
    const int* b = *(const int**)pb;

    return sqrt(a[0]*a[0]+a[1]*a[1])-sqrt(b[0]*b[0]+b[1]*b[1]);
 }
int** kClosest(int** points, int pointsSize, 
    int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
    
    qsort(points, pointsSize, sizeof(int*), cmp);

    int **answer = malloc(k*sizeof(int*));
    for(int i = 0; i < k; i++){
        answer[i] = malloc(2*sizeof(int*));
        answer[i][0] = points[i][0];
        answer[i][1] = points[i][1];
    }
    *returnSize = k;
    *returnColumnSizes = malloc(k*sizeof(int));
    for(int i = 0; i < k; i++){
        (*returnColumnSizes)[i] = 2;
    }
    return answer;

}