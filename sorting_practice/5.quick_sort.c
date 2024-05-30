/*想法:*/
//eg.
//time complexity:
//最佳:
//最差:
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