//題目描述
//Given two strings ransomNote and magazine, 
//return true if ransomNote can be constructed 
//by using the letters from magazine and false otherwise.

//Each letter in magazine can only be used once in ransomNote.

//想法:用一個長度為26的陣列來記錄每個字母的出現次數
//(好處是兩個單字ransomNote跟magazine各走一次就好了)
bool canConstruct(char *ransomNote, char *magazine){
    int i = 0;
    int j = 0;
    int array[26] = {0};
    for(i = 0;i < strlen(magazine); i++ ){
        array[magazine[i] - 'a']++;
        //取出對應字符的計數位置
        //因為 'a' - 'a' = 0，故arry[0]此位置的值+1  
        //array 是一個長度為 26 的整數數組，用來記錄每個小寫字母的出現次數。
        //由於英文字母有 26 個（從 'a' 到 'z'），這個數組的索引範圍是 0 到 25。
    }
    for(j = 0;j < strlen(ransomNote); j++ ){
        array[ransomNote[i] - 'a']--;

        if(array[ransomNote[i] - 'a'] < 0){
            return false;
        }
    }
    return true;
}