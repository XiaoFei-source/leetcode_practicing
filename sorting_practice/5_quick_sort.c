/*想法:從陣列中找出一個基準值，將比基準值小的數值置於基準值的左邊，
比基準值大的數值放在基準值的右邊，再對左右子序列重複以上步驟。
(詳細:找一個基準值pivot(通常為第一個)，後面分往左、往右掃，
由左往右掃得要比基準小，由右往左的要比基準大，找到各一個不符合就2者對調，左右邊掃
碰到的點跟pivot對調，然後分左邊右邊再recursive)*/
//eg.
//time complexity:
//最佳:用的pivot剛好都可以將數列切一半，分割一次要O(N)，遞迴深度logn
//故=O(Nlogn)
//最差:用的pivot剛好都是最大或最小值，每次都只能切出一個
//分割一次要O(N)，遞迴深度O(N)
//故=O(N^2)
//平均情況：O(nlogn)

//swap

void swap(int *a, int *b)
{   
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int arr[], int left, int right)
{   
    int pivotIndex, index_a, index_b;
    if (left < right){
        pivotIndex = left;
        index_a = left;
        index_b = right;
    
        while (index_a < index_b){
            while (arr[index_a] <= arr[pivotIndex] && index_a < right){
                index_a++;
            }
            while (arr[index_b] > arr[pivotIndex]){
                index_b--;
            }
            if(index_a < index_b){
                swap(&arr[index_a], &arr[index_b]);
            }
        }
        swap(&arr[pivotIndex], &arr[index_b]);

        quick_sort(arr, left, index_b-1 );
        quick_sort(arr, index_b+1, right);
        }
}

//測試
int main() {
    int arr[] = {15,9,7,3,11};
    printf("排序前 = ");
    for (int i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    quick_sort(arr,15, 11);

    printf("排序後 = ");
    for (int i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}