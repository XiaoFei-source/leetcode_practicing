//暴力破解法
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *a = (int*)malloc(2*sizeof(int));
    for(int i = 0;i < numsSize;i++)
    {
        for(int j = i+1;(j <numsSize && j != i);j++)
        {
            if(nums[i]+nums[j] == target)
            {
                    a[0] = i;
                    a[1] = j;
            }
        }

    }
    return a;
    
}