// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

//想法順序
// 1.對陣列排序(qsort)，方便指標的指標操作
// 2.主循環:遍歷陣列中的每個元素作為三元素組中的第一個數字
// 3.跳過重複元素:跳過與前一個相同的，避免重複
// 4.計算新目標值並呼叫two sum:對每個元素，計算其相反樹做為目標值，並在剩餘數列中
// 找到兩樹之合可抵銷目標值之數對
// 5.存儲結果:將找到的數隊與當前元素組成三元組並儲存
// 6.釋放two sum分配的內存
// 7.紀錄每個三元祖的大小
// 8.返回包含所有三元祖的二維陣列

//註解還沒寫

int **threesum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes);

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b); 
    //compare函式作為排序函式(e.g. q sort)中的比較器
    //a,b 一開始是cost void*型態，所以需要轉為int*
    //如果 *(int *)a 小於 *(int *)b，返回負值。
                //等於 *(int *)b，返回零。
                //大於 *(int *)b，返回正值。
}

void twosum(int *nums, int numSize, int target,int **results, int *returnSize)
{
    int left = 0, right = numSize -1;
    while (left < right ){
        int sum = nums[left] + nums[right];
        if (sum < target){
            left++;
        } else if (sum > target){
            right--;
        } else {
            results[*returnSize] = (int*)malloc(2*sizeof(int));
            results[*returnSize][0] = nums[left];
            results[*returnSize][1] = nums[right];
            (*returnSize)++;

            do {left--;} while(left < right && nums[left] == nums[left-1]);
            do {right++;} while(left < right && nums[right] == nums[right+1]);
        }
    }
}
int **threesum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), compare);
    //qsort是c語言內建的(在stdlih.h)做排序用
    int **results = (int**)malloc(numsSize *numsSize *sizeof(int*));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++){
        if (i >0 && nums[i] == nums [i-1]) continue;

        int newtarget = -nums[i];
        int twoSumSize = 0;
        int **twoSumResults = (int**)malloc((numsSize - i - 1))*sizeof(int*);
        twoSum(&nums[i + 1], numsSize - i - 1, newtarget, twoSumResults, &twoSumSize);

        for (int j =0; j < twoSumSize; j++){
            results[*returnSize] = (int*)malloc(3*sizeof(int));
            results[*returnSize][0] = nums[i];
            results[*returnSize][1] = twoSumResults[j][0];
            results[*returnSize][2] = twoSumResults[j][1];
        }
        for(int j =0; j < twoSumSize; j++){
            free(twoSumResults[j]);
        }
        free(twoSumResults);
    }
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for (int i = 0;i < *returnSize; i++ ){
        (*returnColumnSizes)[i] = 3;
    }
    return results;
}
