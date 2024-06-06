/*想法:將大筆資料分割成小筆資料做排序，再利用排序好的
小筆資料合併成排序的大筆資料*/
//eg.
//time complexity:
//最佳、最差都是:O(nlogn) 
//平均情況：O(nlogn)

//感覺還可以使用指標改寫，再思考一下
#include <stdio.h>

void merge_sort(int*, int, int);
void merge(int* ,int ,int ,int);

void merge_sort(int *arr, int low, int high)
{
    if (low < high){
        int mid = (low+high)/2;
        merge_sort(arr, low ,mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void merge(int *arr, int low, int mid, int high)
{
    int leftIndex = low;    //左子數列索引
    int rightIndex = mid + 1;   //右子數列索引
    int tempArrLength = high - low + 1;    //臨時數列tempArr的長度
    int tempArr[tempArrLength];     //臨時數列，用來儲存合併過程
    int tempIndex = 0;      //臨時數列索引

    while (leftIndex < mid && rightIndex <= high){ //遍歷左右數列
        if (arr[leftIndex] <= arr[rightIndex]){
            tempArr[tempIndex] = arr[leftIndex];
            leftIndex++;
        } else {
            tempArr[tempIndex] = arr[rightIndex];
            rightIndex++;
        }
        tempIndex++; //左右比較後，儲存至暫存數列
    }
    if (leftIndex > mid){   //若左子數列已經處理完
        while (rightIndex <= high){
            tempArr[tempIndex] = arr[rightIndex];
            rightIndex++;
            tempIndex++;
        }   //將右子數列的剩餘元素依序加入
    } else {    //否則，也就是右子數列已處理完，但左子數列還有東西
        while (leftIndex <= mid){
            tempArr[tempIndex] = arr[leftIndex];
            leftIndex++;
            tempIndex++;
        }   //將左子數列的剩餘元素依序加入
    }
    leftIndex = low; //leftIndex 重置為 low，即合併範圍的起始索引。
    for (tempIndex = 0; tempIndex < tempArrLength; tempIndex++){
        arr[leftIndex] = tempArr[tempIndex];
        leftIndex++;
    }   //將 tempArr 中的元素複製回 arr 的對應位置。
}

//下方為main，可用於測試用
/*
int main() {
    int arr[8] = {4, 6, 1, 9, 5, 3, 0, 2};
    int dataNum = 8;
    int i;

    printf("before sorting: ");
    for (i=0; i<dataNum; i++)
        printf("%d " , arr[i]);
    printf("\n");
    mergeSort(arr, 0, dataNum - 1);
    printf("after sorting: ");
    for (i=0; i<dataNum; i++)
        printf("%d " , arr[i]);
    printf("\n");

    return 0;
}
*/