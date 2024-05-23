/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **insert(int **intervals, int intervalsSize, int *intervalsColsize,
 int *newInterval, int newIntervalSize, 
 int* returnSize, int **returnColumnSizes){
    //intervals是一個二維陣列，int* 指標指向一維整數陣列，
    //而 int** 指標則指向指向一維整數陣列的指標陣列
    //intervals 是一個二維陣列，其中每個元素 intervals[i] 都是一維整數陣列，
    //表示一個區間，因此，intervals 可以表示多個區間的集合
    //intervalsColsize表示每個區間的列大小，應該都為表示每個區間的列大小，應該都為2
    //newInterval為新插入的區間(一維陣列，表示一個區間(包含開始、結束))

    //初始化
    int **res = (int**)malloc(sizeof(int*)*(intervalsSize+1));
    int *colSizes = (int*)malloc(sizeof(int)*(intervalsSize+1));
    int index = 0,resIndex =0;
    //res: 用於儲存結果區間的動態陣列，因為多插入一個，要記得intervalSize要+1
    //index為用於遍歷輸入的區間列表，resIndex用於結果區間(輸出)的索引


    //Before the new interval
    while(index < intervalsSize && intervals[index][1] < newInterval[0]){
        res[resIndex] = intervals[index];
        colSizes[resIndex] = 2;
        //colSizes作用為為每個區間設置列的大小，每個區間由兩個
        //整數組成(開始和結束時)。
        //在某些情況下（尤其是涉及到多維陣列的動態記憶體分配），
        //需要明確告訴調用者每個區間有多少列，這對於正確解析和處理
        //返回的資料非常重要。。
        resIndex++;
        index++;
    }    //將所有'結束時間小於新區間開始時間'的區間直接複製進結果陣列'res'中

    //Merge overlapping intervals with new  interval
    while(index < intervalsSize && intervals[index][0] <= newInterval[1]){
        newInterval[0] = fmin(newInterval[0], intervals[index][0]);
        newInterval[1] = fmax(newInterval[1], intervals[index][1]);
        index++;
        //fmin跟fmax用於取兩個術中的最小跟最大值
    }
    //Add the merged new interval
    int *mergedInterval = (int*)malloc(sizeof(int)*2);
    //mergedInterval是一個指向整數型態的指標，它指向兩個整數的動態記憶體空間。
    mergedInterval[0] = newInterval[0];
    mergedInterval[1] = newInterval[1];
    //創建合併後的新區間
    res[resIndex] = mergedInterval;
    //將 mergedInterval 指向的合併區間插入到結果陣列 res 中：
    colSizes[resIndex] = 2;
    resIndex++;

    //After the new interval
    while(index < intervalsSize){
        //剩下的區間，所以不必特別寫條件(&&)
        res[resIndex] = intervals[index];
        colSizes[resIndex] = 2;
        resIndex++;
        index++;
    }   //將所有'開始時間大於新區間結束時間'的區間直接複製進結果陣列'res'中

    //Set return sizes
    *returnSize = resIndex;
    *returnColumnSizes = colSizes;
    //將結果列表res中有效區間的數量指派給指標 returnSize 指向的位置
    //將指標 returnColumnSizes 指向的位置設置為 colSizes 的位置。
    //colSizes 是一個整數陣列，存儲著每個區間的列大小，即每個區間的元素個數。
    return res;
 }