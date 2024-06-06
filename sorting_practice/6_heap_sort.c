/*想法:*/
//eg.
//time complexity:
//最佳:
//最差:
//平均情況：O(nlogn)
#include<stdio.h>
#define N 100
void HeapAdjust(int a[], int s, int m)
{
    int root, i;
    root = a[s];    //暫存根節點
    for (i = 2 * s; i <= m; i = i * 2){ //循環遍歷子樹，i指向左子節點(2*s會=s的左邊子孫)
        if (a[i] < a[i + 1] && i < m){    //左右比較，若右邊大，選右邊子節點
            i++;
        }
        if (root > a[i]){
            break;  //若root大於子節點，不用調整
        }
        else{
            a[s] = a[i];
            s = i;
        }   //子節點上移，並繼續調整子樹
    }
    a[s] = root;
}
void HeapSort(int a[], int n)
{
    int i;
    int temp;
    for (i = n / 2; i >0 ; i--){    //從最後ˋ一個非葉子節點開此(聯想到圖，比較好懂)
        HeapAdjust(a, i, n);        //ex 有5個，就從5/2=2.5(無條件捨去)，第二個開始
    }
    for (i = n; i > 0; i--){
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;    //將根節點與最後一個子節點交換，回想到圖(右下角)
        HeapAdjust(a, 1, i-1);  //調整剩下的堆
    }
    for(i = 1; i <= n;i++){ //結束後依序列印，由小到大
        printf("%d\t", a[i]);
    }
}
int main()
{
    int n, i;
    int a[N];
    printf("請輸入要排序的數字個數:\n");
    scanf("%d", &n);
    printf("請順序輸入%d個數字:\n",n);
    for (i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    printf("經過排序後的數字為:\n");
    HeapSort(a, n);
    return 0;
}
/*圖片          a[1]
                /  \
               /    \
            a[2]    a[3]
             / \     
            /   \   
         a[4]   a[5]
         */
        