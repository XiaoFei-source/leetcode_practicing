//Given an integer array nums, find the subarray
//with the largest sum, and return its sum.

//想法:(有4種)
//1.暴力法
//2.Dynamic programming
//3.Greedy
//4.Divide and conquer

//Dynamic programming
//sum儲存使用上一個數字的連續和，sum加上當前數字，如果和>0，
//則可以繼續向後，小於0則代表當前位置是一負數，應從下一個數字開始，
//同時不斷更新max

//時間複雜度是 O(n)
int maxSubArray(int *nums, int numsSize){
    int i = 0, sum = 0;
    int max = nums[0];

    for(i = 0; i < numsSize; i++){
        sum += nums[i];
        if(max < sum)
            max = sum;
        if(sum < 0)
            sum = 0;
    }
    return max;
}