//想法:反覆比較相鄰的兩元素，並根據大小交換位置。
//eg.較大的逐漸(冒泡)到尾端，較小的逐漸沉底
//每一趟排序都會使至少一個元素達到最終位置，直到數列完全有序。
//忽略已排序的末尾元素，重複步驟
//time complexity:
//最佳(已排序):O(n)，只需一次遍歷即可確認，時間複雜度為線性。
/*最差(完全逆順序): O(n^2)需要進行 n-1 次迭代，
次迭代比較和交換 n-i 次，總時間複雜度為平方級。*/
//平均情況： O(n^2)

void bubble_sort(int arr[], int n)
{
    for(int i =0;i < n; i++){
        for(int j = 0;j < i; ++j){
            if(arr[j] > arr[i]){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            } 
        }
    }
}
//此處arr[]寫法已經涉及指標操作，*(arr + j) 相當於 arr[j]

//參考 swap 常見寫法
void swap(int *a, int *b)
{
    int temp;   // 取得指標 a 指向的值
    temp = *a;  // 將指標 b 指向的值賦給指標 a
    *a = *b;    // 將 temp 的值（原指標 a 的值）賦給指標 b
    *b = temp;
}
//call funtion時
//swap(&x,&y); 定義了兩個整數變數 x 和 y，並將它們的地址傳遞給 swap 函數。