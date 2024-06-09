/*想法:不斷的從未排序的數列中掃過一遍挑出最小(最大)的放到第一個(最後一個)*/
//eg.
//time complexity:
//最佳(已排序):(O(n^2))
/*最差(完全逆順序): (O(n^2))
次迭代比較和交換 */
//平均情況：(O(n^2))
#include <stdio.h>
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++){
        int min_index = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min_index]){
                min_index =j;
            }
        }
        //swap
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}
int main() {
    int arr[] = {10,8,6,2,4};
    printf("排序前 = ");
    for (int i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    selection_sort(arr, 5);

    printf("排序後 = ");
    for (int i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}