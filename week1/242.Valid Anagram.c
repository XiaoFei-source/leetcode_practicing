bool isAnagram(char *s, char *t){
    int check_s[26]={0};
    int i;
    int indexs;
    int indext;

    if (strlen(s)!=strlen(t))               //字串長度先比一次，不對直接返回false
        return false;
    for(i = 0;(s[i]!='\0')&&(t[i]!='\0');i++)
    {       
        indexs = s[i] - 'a';
        check_s[indexs]++;
        indext = t[i] - 'a';
        check_s[indext]--;  
    }
    
    for(i=25;i>=0;i--)
    {
        if(check_s[i] != 0)
        return false;
    }
    return true;
}
//尚未改好