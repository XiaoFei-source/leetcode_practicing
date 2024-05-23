//題目描述
//Given a string s, find the length of the longest 
//substring without repeating characters.

//想法:hash table 紀錄
int lengthOfLongestSubstring(char *s){
    int *ht = (int*)malloc(128*sizeof(int)), i;
    //分配一個大小為128的整數陣列ht，用來記錄ASCII最近一次出現的位置
    for(i = 0; i < 127; i++){
        ht[i] = -1;
        //ht(hash table) 陣列中的所有元素初始化為 -1，表示每個字符都還未出現。
    }
    int max = 0, strsize = strlen(s), substring_start = 0;
    //max用來記錄目前最常無重複字串的長度
    //strsize是輸入字串s的長度
    //substring_start 記錄當前無重複子字串的起始位置
    for(i = 0; i < strsize; i++){
        if(ht[s[i]]>=substring_start){
            //一開始出現的字都會進else分支
            //出現重複字母才會進if敘述(因為ht[s[i]]過一次後就被更新了)
            substring_start = ht[s[i]] + 1;
            //從要被替代的字母的位置再+1開始
            ht[s[i]] = i;
            //hash table數值更新
        }
        else{
            ht[s[i]] = i;
            //hash table數值更新
            if(i - substring_start + 1 >max){
                max = i - substring_start + 1;
            }
        }
    }
    return max;
}

//範例
//eg
// i = 0，字符 s[0] = 'a'：
// ht['a'] 是 -1（未出現過），進入 else 分支。
// ht['a'] = 0（記錄 'a' 最近出現的位置）。
// 更新 max = max(0, 0 - 0 + 1) = 1。

// i = 1，字符 s[1] = 'b'：
// ht['b'] 是 -1，進入 else 分支。
// ht['b'] = 1。
// 更新 max = max(1, 1 - 0 + 1) = 2。

// i = 2，字符 s[2] = 'c'：
// ht['c'] 是 -1，進入 else 分支。
// ht['c'] = 2。
// 更新 max = max(2, 2 - 0 + 1) = 3。

// i = 3，字符 s[3] = 'a'：
// ht['a'] 是 0（'a' 最近出現的位置在 substring_start 之後）。
// 進入 if 分支，更新 substring_start = ht['a'] + 1 = 1。
// 更新 ht['a'] = 3（更新 'a' 的出現位置）。