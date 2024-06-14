#include <stdio.h>
#define MAX_SIZE 100

int num[MAX_SIZE]; // 全局數列
int tmp[MAX_SIZE]; // 暫存陣列

void merge(int left, int right){
   int mid = (left + right) / 2;
    int i = left;     // 左半部分的起始索引
    int j = mid + 1;  // 右半部分的起始索引
    int k = left;     // 暫存陣列的起始索引

    // 合併兩個部分到暫存陣列 tmp 中
    while (i <= mid && j <= right) {
        if (num[i] <= num[j]) {
            tmp[k] = num[i];
            i++;
        } else {
            tmp[k] = num[j];
            j++;
        }
        k++;
    }

    // 將剩餘的元素從左半部分複製到 tmp
    while (i <= mid) {
        tmp[k] = num[i];
        i++;
        k++;
    }

    // 將剩餘的元素從右半部分複製到 tmp
    while (j <= right) {
        tmp[k] = num[j];
        j++;
        k++;
    }

    // 將 tmp 中的元素複製回原始數列 num
    for (i = left; i <= right; i++) {
        num[i] = tmp[i];
    }
}

void mergeSort(int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merge(left, right);
    }
}
/*int main(void){
    mergeSort(0, 9);
    return 0;
}*/
int main() {
    int arr[8] = {4, 6, 1, 9, 5, 3, 0, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;

    printf("before sorting: ");
    for (i=0; i< n; i++)
        printf("%d " , arr[i]);
    printf("\n");
  //  merge_sort(arr, 0, dataNum - 1);
    mergeSort(0, n-1);
    printf("after sorting: ");
    for (i=0; i< n; i++)
        printf("%d " , arr[i]);
    printf("\n");

    return 0;
}