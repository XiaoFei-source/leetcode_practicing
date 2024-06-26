/*想法:構建有序序列，對於排序的序列，
在已排序的序列中從後面往前掃，找到對應位置並插入*/
/*1.从第一个元素开始，该元素可以认为已经被排序；
2.取出下一个元素，在已经排序的元素序列中从后向前扫描；
3.如果该元素（已排序）大于新元素，将该元素移到下一位置；
4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
5.将新元素插入到该位置后；
6.重复步骤2~5。*/
//time complexity:
//最佳(已排序):O(n)
/*最差(完全逆順序):(O(n^2) */
//平均情況： (O(n^2))
#include<stdio.h>
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n ; i++){
        int j = i;
        int temp;
        while (j > 0 && arr[j - 1] > arr[j]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;        //j 從當前元素的位置 i 開始，向"前"遍歷已排序部分
                        //所以需要j--(e.g.j[5]->j[4]->j[3]...)
        }
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertion_sort(arr, n);

    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}