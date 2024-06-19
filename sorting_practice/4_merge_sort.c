/*想法:將大筆資料分割成小筆資料做排序，再利用排序好的
小筆資料合併成排序的大筆資料*/
//eg.
//time complexity:
//最佳、最差都是:O(nlogn) 
//平均情況：O(nlogn)

//感覺還可以使用指標改寫，再思考一下
#include <stdio.h>
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int middle, int right);

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        merge_sort(arr, left, middle);  //左邊
        merge_sort(arr, middle + 1, right); //右邊
        merge(arr, left, middle, right);    //合併兩個排好的
    }
}

// 合併函數
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2]; // 創建臨時陣列

    for (i = 0; i < n1; i++) {      // 複製數據到臨時陣列
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    // 合併臨時陣列回原陣列
    i = 0; // 初始左半部分索引
    j = 0; // 初始右半部分索引
    k = left; // 初始合併後陣列索引

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 複製剩餘元素（如果有的話）
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


//下方為main，可用於測試用

int main() {
    int arr[8] = {4, 6, 1, 9, 5, 3, 0, 2};
    int dataNum = 8;
    int i;

    printf("before sorting: ");
    for (i=0; i<dataNum; i++)
        printf("%d " , arr[i]);
    printf("\n");
    merge_sort(arr, 0, dataNum - 1);
    printf("after sorting: ");
    for (i=0; i<dataNum; i++)
        printf("%d " , arr[i]);
    printf("\n");

    return 0;
}