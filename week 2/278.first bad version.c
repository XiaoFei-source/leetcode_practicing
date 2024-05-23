//The API isBadversion is defined for you
//bool isBadVersion(int version); 已定義完，用於尋找壞掉產品的函數

//想法:Binary search(二分搜尋) 
//time complexity:O(logn)
int firstBadVersion(int n){
    long mid, low = 1, high = n;
    while(low < high)
    {
        mid = (high + low)/2;

        if(isBadversion(mid)){
            high = mid;
        //如果mid 是壞掉的版本，代表第一個壞的在mid或是更前面，並將high更新為mid
        }
        else {
            low = mid + 1;
        //如果mid 是好的版本，代表第一個壞的在mid後面，並將low更新為mid+1    
        }
    }
    return low;

}