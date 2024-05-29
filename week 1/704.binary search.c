//使用binary search
int search(int *nums, int numsSize, int target){
    int low = 0, upper = numsSize - 1;

    while(low <= upper){
        int mid = low + (upper - low)/2;

        if(nums[mid] == target){
            return mid;
        }else if (nums[mid] < target){
            low = mid+1;
        }else {
            upper = mid-1;
        }
    }
    return -1;

}

//線性搜尋法
int search(int *nums, int numsSize, int target){
    int i ;
    for (i=0;i<numsSize-1;i++){
        if (nums[i] == target)
            return nums[i];
    }
    return -1;
}